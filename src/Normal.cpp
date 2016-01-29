#include <cmath>
#include <algorithm>
#include <iostream>
#include "Normal.h"

bool Norm::fuzzyCompare(double num1, double num2, double absoluteTolerance){
	return abs(num1-num2)<abs(absoluteTolerance);
}
double Norm::CDF(Norm::PDF pdf, double min, double max){
	if(min > max){ 
		std::swap(min, max);
	}

	double total = 0;
	double dx = std::get<1>(pdf)/100;
	for(double i = min; i < max; i+=dx){
		total+=(getValue(pdf, i)+getValue(pdf, i+dx))/2*dx;
	}
	return total;
}
double Norm::getValue(Norm::PDF pdf, double value){
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;
	return 1/(std::get<1>(pdf)*sqrt(2*pi))*pow(e, -1*pow(value-std::get<0>(pdf),2)/(2*pow(std::get<1>(pdf),2)));
}
double Norm::invNorm(Norm::PDF pdf, double percent){ 
	int sign = Norm::sgn(percent); 
	double dx = std::get<1>(pdf)/100;
	double iterator = 2;
	for(iterator = std::get<0>(pdf); Norm::CDF(pdf, std::get<0>(pdf), iterator) < percent; iterator+=dx){
		if(Norm::fuzzyCompare(Norm::CDF(pdf, std::get<0>(pdf), iterator), percent, 0.005)){
			return sign ? iterator : std::get<0>(pdf) - (iterator - std::get<0>(pdf));
		}	

	}
	return sign ? iterator : std::get<0>(pdf) - (iterator - std::get<0>(pdf));	 
}
template <typename T> int Norm::sgn(T val){
    return (T(0) < val) - (val < T(0));
}
