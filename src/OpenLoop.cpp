#include "OpenLoop.h"

OpenLoop::OpenLoop(std::unique_ptr<Function> regulatingFunction){
  this->regulatingFunction = std::move(regulatingFunction);
  accTime = 0;
}

void OpenLoop::Update(double dT){
  this->accTime += dT;
  useOutput((*regulatingFunction)(accTime));
}

void OpenLoop::addTarget(std::shared_ptr<Thruster> newTarget){
  targets.push_back(newTarget);
}

double OpenLoop::getCurrentOutput(){
  return currentOutput;
}

void OpenLoop::useOutput(double output){
  this->currentOutput = output;
  for(std::shared_ptr<Thruster> target : targets){
    target->setPower(output);
  }
}

