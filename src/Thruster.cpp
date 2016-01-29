#include "Thruster.h"

Eigen::Vector3d Thruster::viewThrust(){
	return thrust;
}
Eigen::Vector3d Thruster::getThrust(){ //Need to add variance...
	return thrust*power;
} 
void Thruster::setThrust(Eigen::Vector3d newThrust){
	thrust = newThrust;
}

void Thruster::setPower(double newPower){
	power = newPower>1 ? 1 : (newPower<-1 ? -1 : newPower); //Constrains power to -1<power<1
}
double Thruster::getPower(){
	return power;
}
	
void Thruster::setThrustVariance(Eigen::Vector3d newThrustVariance){
	thrustVariance = newThrustVariance;
}
Eigen::Vector3d Thruster::getThrustVariance(){
	return thrustVariance;
}
