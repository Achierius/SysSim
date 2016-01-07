#include "Thruster.h"

Eigen::Vector3f Thruster::viewThrust(){
	return thrust;
}
Eigen::Vector3f Thruster::getThrust(){ //Need to add variance...
	return thrust*power;
} 
void Thruster::setThrust(Eigen::Vector3f newThrust){
	thrust = newThrust;
}

void Thruster::setPower(float newPower){
	power = newPower>1 ? 1 : (newPower<-1 ? -1 : newPower); //Constrains power to -1<power<1
}
float Thruster::getPower(){
	return power;
}
	
void Thruster::setThrustVariance(Eigen::Vector3f newThrustVariance){
	thrustVariance = newThrustVariance;
}
Eigen::Vector3f Thruster::getThrustVariance(){
	return thrustVariance;
}
