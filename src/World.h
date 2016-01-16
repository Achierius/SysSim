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
	Body* getBody(int numBody);
	void removeBody(int numBody);
private:
	vector<Body> Bodies;	
	float dT;
};
