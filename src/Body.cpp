#include "Body.h"

void Body::setMass(double newMass){
	mass = std::abs(newMass);
}
void Body::setRadius(double newRadius){
	radius = std::abs(newRadius);
}


Body::Body(Eigen::Vector3d posInit, Eigen::Vector3d velInit, double massInit, double radiusInit){
	position = posInit;
	velocity = velInit;
	mass = std::abs(massInit);
	radius = std::abs(radiusInit);
}

Eigen::Vector3d Body::getPos(){
	return position;
}
Eigen::Vector3d Body::getVel(){
	return velocity;
}
Eigen::Vector3d Body::getAcc(){
	return acceleration;
}
double Body::getMass(){
	return mass;
}
double Body::getRadius(){
	return radius;
}

void Body::addSensor(Sensor* newSensor){
	Sensors.push_back(newSensor);
}
void Body::addThruster(Thruster* newThruster){
	Thrusters.push_back(newThruster);
}
void Body::addSensor(int placeAfter, Sensor* newSensor){
	Sensors.insert(Sensors.begin()+(placeAfter-1), newSensor);

}
void Body::addThruster(int placeAfter, Thruster* newThruster){
	Thrusters.insert(Thrusters.begin()+(placeAfter-1), newThruster);
}

void Body::removeSensor(int sensorNo){
	Sensors.erase(Sensors.begin()+(sensorNo-1));
}
void Body::removeThruster(int thrusterNo){
	Thrusters.erase(Thrusters.begin()+(thrusterNo-1));
}

double Body::getSensorValue(int sensorNo){
	return (Sensors[sensorNo-1])->getReading();
}

Eigen::Vector3d Body::calculateThrustVector(){
	Eigen::Vector3d plc(0,0,0);
	//for(Thruster thrust:Thrusters){plc+=thrust.getThrust();} //I can dream, Harold
	for(auto itr = Thrusters.begin(); itr!=Thrusters.end(); ++itr){
		plc+=(*itr)->viewThrust();
	}
	return plc;
}

void Body::Update(double dt){
	acceleration = this->calculateThrustVector()/this->getMass();
	position+=dt*velocity+dt*dt/2*acceleration;
	velocity+=dt*acceleration;
}
