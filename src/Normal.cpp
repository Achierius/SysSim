#include <cmath>
#include <algorithm>
#include "Normal.h"

bool Norm::fuzzyCompare(float num1, float num2, float absoluteTolerance){
	return abs(num1-num2)<abs(absoluteTolerance);
}
float Norm::CDF(Norm::PDF pdf, float min, float max){
	if(min > max){ 
		std::swap(min, max);
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
	if(abs(percent) > 0.5){percent = percent/(2*abs(percent));}
	int direction = abs(percent)/percent;
	float dx = std::get<1>(pdf)/500;
	float iterator;
	for(iterator = std::get<0>(pdf); Norm::CDF(pdf, std::min(iterator, std::get<0>(pdf)), std::max(iterator, std::get<0>(pdf))) > percent; iterator+=dx*direction){
		if(fuzzyCompare(Norm::CDF(pdf, std::min(iterator, std::get<0>(pdf)), std::max(iterator, std::get<0>(pdf))), percent, 0.05)){
			return iterator;
		}	

	}
	return iterator;	 
}

