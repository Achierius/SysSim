#ifndef __SYSSIM_CLOSED_LOOP_H
#define __SYSSIM_CLOSED_LOOP_H

#include "Controller.h"
#include <memory>

class ClosedLoop : Controller {
public:
  virtual void addSensor(std::shared_ptr<Sensor> newSensor) = 0;
private:
  std::vector< std::shared_ptr<Sensor> > sensors;
};

#endif//__SYSSIM_CLOSED_LOOP_H
