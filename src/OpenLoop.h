#ifndef __SYSSIM_OPEN_LOOP_H
#define __SYSSIM_OPEN_LOOP_H

#include "Function.h"
#include "Controller.h"
#include "Thruster.h"
#include <Eigen/Eigen/Dense>
#include <memory>

class OpenLoop : Controller {
public:
  OpenLoop(std::unique_ptr<Function> regulatingFunction);

  void Update(double dT) override;

  void addTarget(std::shared_ptr<Thruster> newTarget) override;

  double getCurrentOutput();

private:
  double accTime;
  double currentOutput;

  void useOutput(double output) override;

  std::unique_ptr<Function> regulatingFunction;
};

#endif//__SYSSIM_OPEN_LOOP_H
