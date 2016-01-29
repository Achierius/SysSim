#ifndef _THRUSTER_H
#define _THRUSTER_H

#include <Eigen/Dense>

class Thruster{
public:
	void setThrust(Eigen::Vector3f newThrust);
	Eigen::Vector3f viewThrust(); //Just gives the Thrust vector
	Eigen::Vector3f getThrust(); //Calculates with added variance & power

	void setPower(float newPower);
	float getPower();

	void setThrustVariance(Eigen::Vector3f newThrustVariance);
	Eigen::Vector3f getThrustVariance();



private:
	Eigen::Vector3f thrust;
	float power;
	Eigen::Vector3f thrustVariance;
};

#endif
