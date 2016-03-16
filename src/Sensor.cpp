#include "Sensor.h"
#include <ctime>
#include <cmath>

double Sensor::getValue(){ //returnValue gives the correct sensor output, while returnReading adds in sensor noise. Or will.
	return value;
}
double Sensor::getReading(){
	return value; //NEEDS TO INCORPORATE VARIANCE AAAAAH
}

void Sensor::setVariance(double newVariance){
	variance = newVariance;
}
double Sensor::getVariance(){
	return variance;
}

void Sensor::setParent(std::unique_ptr<Body> newParent){ //Do I need const here?
	parent = newParent; //NEEDS TO CHANGE THE COVARIANCE MATRIX WHEN I ADD THAT
}
