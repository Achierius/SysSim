#include "OpenLoop.h"

OpenLoop::OpenLoop(Function* regulatingFunction){
  this->regulatingFunction = regulatingFunction;
  accTime = 0;
}

void OpenLoop::Update(double dT){
  this->accTime += dT;
  useOutput((*regulatingFunction)(accTime));
}

void OpenLoop::addTarget(Thruster* newTarget){
  targets.push_back(newTarget);
}

double OpenLoop::getCurrentOutput(){
  return currentOutput;
}

void OpenLoop::useOutput(double output){
  this->currentOutput = output;
  for(Thruster* target : targets){
    target->setPower(output);
  }
}

