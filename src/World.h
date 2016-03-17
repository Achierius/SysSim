#include "Body.h"
#include "Thruster.h"
#include "Sensor.h"
#include <Eigen/Eigen/Dense>
#include <memory>
#include <vector>

class World{
public:
	World(double initDT);
	void Update();
	void addBody(std::unique_ptr<Body> newBody);
	void removeBody(int numBody);
private:
  std::vector< std::unique_ptr<Body> > Bodies;
	double dT;
};
