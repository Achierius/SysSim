#ifndef _SENSOR_H
#define _SENSOR_H

#include <Eigen/Eigen/Dense>

class Sensor{
public:
	template<typename T>;
	virtual T getValue() = 0;		
private:

};


#endif
