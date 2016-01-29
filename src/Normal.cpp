#include <cmath>
#include "Normal.h"

float Norm::CDF(Norm::PDF pdf, float min, float max){
	if(min > max){ //This swaps the two using the XOR swap algorithm
		min = min ^ max;
		max = max ^ min;
		min = min ^ max;
	}

	float total = 0;
	float dx = std::get<1>(pdf)/500;
	for(float i = min; i < max; i+=dx){
		total+=(getValue(pdf, i)+getValue(pdf, i+dx))/2*dx;
	}
	return total;
}
float Norm::getValue(Norm::PDF pdf, float value){
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;
	return 1/(std::get<1>(pdf)*sqrt(2*pi))*pow(e, -1*pow(value-std::get<0>(pdf),2)/(2*pow(std::get<1>(pdf),2)));
}
float Norm::invNorm(Norm::PDF pdf, float percent){ 
	if(abs(percent) > 1){percent = percent/abs(percent);}
	int direction = abs(percent)/percent;
	float dx = std::get<1>(pdf)/500;
	for(float i = std::get<0>(pdf); true; i+=dx*direction){
		if(abs(Norm::CDF(pdf, i < std::get<0>(pdf) ? i : std::get<0>(pdf), i > std::get<0>(pdf ? std::get<0>(pdf) : i) - percent) < 0.001){return i;};
	}
	return 0;	 
}

