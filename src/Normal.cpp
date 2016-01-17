#include <math.h>
#include "Normal.h"
float Norm::CDF(Norm::PDF pdf, float min, float max){
	float total = 0;
	for(float i = min; i < max; i+=0.001){
		total+=(getValue(pdf, i)+getValue(pdf, i+0.001))/2*0.001;
	}
	return total;
}
float Norm::getValue(Norm::PDF pdf, float value){
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;
	return 1/(std::get<1>(pdf)*sqrt(2*pi))*pow(e, -1*pow(value-std::get<0>(pdf),2)/(2*pow(std::get<1>(pdf),2)));
}

