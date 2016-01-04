#ifndef _THRUSTER_H
#define _THRUSTER_H

#include <Eigen/Eigen/Dense>

class Thruster{
public:
	void SetThrust(Eigen::Vector3f newThrust);
	Vector3f ViewThrust(); //Just gives the Thrust vector
	Vector3f GetThrust(); //Calculates with added variance

	void SetPower(float newPower);
	float GetPower();

	void SetThrustVariance(Eigen::Vector3f newThrustVariance);
	Eigen::Vector3f geThrustVariance();


private:
	Eigen::Vector3f Thrust;
	float Power;
	Eigen::Vector3f ThrustVariance;
};

#endif
