#include "Sensor.h"
#include <ctime>
#include <cmath>

float Sensor::getValue(){ //returnValue gives the correct sensor output, while returnReading adds in sensor noise. Or will.
	return value;
}
float Sensor::getReading(){
	return value; //NEEDS TO INCORPORATE VARIANCE AAAAAH
}

void Sensor::setVariance(float newVariance){
	variance = newVariance;
}
float Sensor::getVariance(){
	return variance;
}

Body* Sensor::getParent(){
	return parent;
}
void Sensor::setParent(Body* newParent){ //Do I need const here?
	parent = newParent; //NEEDS TO CHANGE THE COVARIANCE MATRIX WHEN I ADD THAT
}
