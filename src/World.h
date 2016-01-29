#include "Body.h"
#include "Thruster.h"
#include "Sensor.h"
#include <Eigen/Dense>
#include <vector>

class World{
public:
	World(double initDT);
	Update();
	void addBody(Body newBody);
	Body* getBody(int numBody);
	void removeBody(int numBody);
private:
	vector<Body> Bodies;
	double dT;
};
