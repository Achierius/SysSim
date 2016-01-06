#include "Thruster.h"

Eigen::Vector3f Sensor::viewThrust(){
	return thrust;
}
Eigen::Vector3f Thruster::getThrust(){ //Need to add variance...
	return thrust*power;
} 
void Thruster:setThrust(float newThrust){
	thrust = newThrust;
}

void Sensor::setPower(float newPower){
	power = newPower>1 ? 1 : (newPower<-1 ? -1 : newPower); //Constrains power to -1<power<1
}
void Sensor::getPower(){
	return power;
}
	
void Sensor::setThrustVariance(Eigen::Vector3f newThrustVariance){
	thrustVariance = newThrustVariance;
}
Eigen::Vector3f Sensor::getThrustVariance(){
	return thrustVariance;
}
