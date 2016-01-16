#include "Body.h"
#include "Thruster.h"
#include "Sensor.h"
#include <Eigen/Eigen/Dense>
#include <Vector>

class World{
public:
	World(float initDT);
	Update();
	void addBody(Body newBody);
private:
	vector<Body> Bodies;	
};
