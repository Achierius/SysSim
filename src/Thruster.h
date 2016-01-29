#ifndef _THRUSTER_H
#define _THRUSTER_H

#include <Eigen/Eigen/Dense>

class Thruster{
public:
	void setThrust(Eigen::Vector3d newThrust);
	Eigen::Vector3d viewThrust(); //Just gives the Thrust vector
	Eigen::Vector3d getThrust(); //Calculates with added variance & power

	void setPower(double newPower);
	double getPower();

	void setThrustVariance(Eigen::Vector3d newThrustVariance);
	Eigen::Vector3d getThrustVariance();



private:
	Eigen::Vector3d thrust;
	double power;
	Eigen::Vector3d thrustVariance;
};

#endif
