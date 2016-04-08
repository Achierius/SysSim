#include "Sine.h"
#include <cmath>
#include <iostream>

Sine::Sine(double amplitude, double period, double phase){
  this->phase = phase;
  this->period = period;
  this->amplitude = amplitude;
}
Sine::Sine(double amplitude, double period){
  this->phase = 0;
  this->period = period;
  this->amplitude = amplitude;
}
Sine::Sine(double amplitude){
  this->phase = 0;
  this->period = 2*pi;
  this->amplitude = amplitude;
}
Sine::Sine(){
  std::cout<<this->calculate(3*pi/2)<<std::endl;
  this->phase = 0;
  this->period = 2*pi;
  this->amplitude = 1;
}

double Sine::operator()(double input){
  return calculate(input);
}

double Sine::calculate(double input){
  input = input-2*pi*floor(input/(2*pi));
  double sum = 0;
  for(int i = 1; i < 5; i++){
    sum += std::pow((-1),(i-1.0))*std::pow((input),(2*i-1))/[](int i){int b = 1; for(i; i > 1; i--){b*=i;} return b;}(2*i-1);
  }
  return sum;
}
