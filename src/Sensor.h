#ifndef _SENSOR_H
#define _SENSOR_H

#include <Eigen/Eigen/Dense>
#include "Body.h"

class Body;
 
class Sensor{
public:
	template<typename T>;
	virtual T updateValue();		
	
	void setVariance(float newVariance);
	float getVariance();

	Body* getParent();
	void setParent(const Body* newParent);
private:
	Body* parent;
	T value;
	float variance;
	//The values which lead to the necessity of a covariance matrix in Kalman filtering are dealt with in the actual positional values.

};


#endif
