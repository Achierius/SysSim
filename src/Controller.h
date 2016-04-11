#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <Eigen/Dense>
#include "Thruster.h"
#include <vector>

class Controller{
public:

	virtual void useOutput() = 0;
	virtual void addTarget(Thruster* newTarget) = 0;
protected:
	std::vector<Thruster*> targets;


};
#endif

