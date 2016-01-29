#ifndef _SENSOR_H
#define _SENSOR_H

#include <Eigen/Eigen/Dense>
#include "Body.h"

class Body;

class Sensor{
public:
	virtual void updateValue()=0;
	double getValue();
	double getReading();

	void setVariance(double newVariance);
	double getVariance();

	Body* getParent();
	void setParent(Body* newParent);
private:
	Body* parent;
	double value;
	double variance;
	//The values which lead to the necessity of a covariance matrix in Kalman filtering are dealt with in the actual positional values.
};


#endif
