#ifndef _BODY_H
#define _BODY_H
#include <Eigen/Dense>
#include <Vector>
#include "Thruster.h"
#include "Sensor.h"

class Sensor;

class Body{
public:
	Body(Eigen::Vector3f posInit, Eigen::Vector3f velInit, float massInit,float radiusInit);
	Body(Eigen::Vector3f posInit, float massInit, float radiusInit); 
	Eigen::Vector3f getPos();
	Eigen::Vector3f getVel();
	Eigen::Vector3f getAcc();
	float getMass();
	float getRadius();

	void setMass( float newMass );
	void setRadius( float newRadius );

	//Need to add the Sensor class

	void addSensor(Sensor* newSensor);
	void addSensor(int placeAfter, Sensor* newSensor);
	void reorderSensors(int sensorNo, int placeAfter);
	void removeSensor(int sensorNo);

	Sensor* getSensor(int sensorNo);
	float getSensorValue(int sensorNo);
	
	//Need to add the Thruster class

	void addThruster(Thruster newThruster);
	void addThruster(int placeAfter, Thruster newThruster);
	void reorderThrusters(int thrusterNo, int placeAfter);
	void removeThruster(int thrusterNo);

	void changeThrust(int thrusterNo, double percent);
	Eigen::Vector3f calculateThrustVector();
	Thruster* getThruster(int thrusterNo);

	void Update(float dt);

	friend class Sensor;
	//Add in Controllers later as well as Estimators
	//Need to define how state changes over time
	//Collisions? Later. Assume single, phasing body for now.
	//Need to set up resistive forces. Air, ground resistance? Gravity? I think those might just be in the world.
private:
	std::vector<Sensor*> Sensors; //http://stackoverflow.com/questions/27773640/c-passing-a-list-of-a-class-with-elements-of-a-subclass
	std::vector<Thruster> Thrusters;
	Eigen::Vector3f position;
	Eigen::Vector3f velocity;
	Eigen::Vector3f acceleration;
	float radius;
	float mass;

		
}; 



#endif
