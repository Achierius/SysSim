#include "Body.h"

void Body::setMass(float newMass){
	mass = abs(newMass);
}
void Body::setRadius(float newRadius);{
	radius = abs(newRadius);
}


Body::Body(Eigen::Vector3f posInit, Eigen::Vector3f velInit, float massInit, float radiusInit);{
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
Eigen::Vector3f Body:getAcc(){
	return acceleration;
}
float Body::getMass(){
	return mass;
}
float Body::getRadius(){
	return radius;
}

void addSensor(Sensor newSensor){
	Sensors.push_back(newSensor);
}
void addThruster(Thruster newThruster){
	Thrusters.push_back(newThruster);
}
void addSensor(int placeAfter, Sensor newSensor){
	Sensors.insert(Sensors.begin()+(n-1), newSensor);
}
void addThruster(int placeAfter, Thruster newThruster){
	Thrusters.insert(Thrusters.begin()+(n-1), newSensor);
}
void removeSensor(int sensorNo){
	Sensors.erase(Sensors.begin()+(n-1);
}
void removeThruster(int thrusterNo){
	Thrusters.erase(Thrusters.begin()+(n-1));
}
float getSensorValue(int sensorNo){ 
	return Sensors[sensorNo-1].
