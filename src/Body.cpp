#include "Body.h"

void Body::setMass(float newMass){
	mass = abs(newMass);
}
void Body::setRadius(float newRadius){
	radius = abs(newRadius);
}


Body::Body(Eigen::Vector3f posInit, Eigen::Vector3f velInit, float massInit, float radiusInit){
	position = posInit;
	velocity = velInit;
	mass = abs(massInit);
	radius = abs(radiusInit);
}

Eigen::Vector3f Body::getPos(){
	return position;
}
Eigen::Vector3f Body::getVel(){
	return velocity;
}
Eigen::Vector3f Body::getAcc(){
	return acceleration;
}
float Body::getMass(){
	return mass;
}
float Body::getRadius(){
	return radius;
}

void Body::addSensor(Sensor* newSensor){
	Sensors.push_back(newSensor);
}
void Body::addThruster(Thruster newThruster){
	Thrusters.push_back(newThruster);
}
void Body::addSensor(int placeAfter, Sensor* newSensor){
	Sensors.insert(Sensors.begin()+(placeAfter-1), newSensor);
}
void Body::addThruster(int placeAfter, Thruster newThruster){
	Thrusters.insert(Thrusters.begin()+(placeAfter-1), newThruster);
}

void Body::removeSensor(int sensorNo){
	Sensors.erase(Sensors.begin()+(sensorNo-1));
}
void Body::removeThruster(int thrusterNo){
	Thrusters.erase(Thrusters.begin()+(thrusterNo-1));
}

float Body::getSensorValue(int sensorNo){ 
	return Sensors[sensorNo-1]->getReading();
}

Eigen::Vector3f Body::calculateThrustVector(){
	Eigen::Vector3f plc(0,0,0);
	//for(Thruster thrust:Thrusters){plc+=thrust.getThrust();} //I can dream, Harold
	for(std::vector<Thruster>::iterator itr = Thrusters.begin(); itr!=Thrusters.end(); ++itr){
		plc+=itr->viewThrust();
	}
	return plc;
}
		
void Body::Update(float dt){
	acceleration = this->calculateThrustVector()/this->getMass();
	position+=dt*velocity+dt*dt/2*acceleration;
	velocity+=dt*acceleration;
}
