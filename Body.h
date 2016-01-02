#ifndef _BODY_H
#define _BODY_H
#include <Eigen/Eigen/Dense>
#include <Vector>
#include "Thruster.h"
#include "Sensor.h"

class Body{
public:
	Body(Eigen::Vector3f posInit, Eigen::Vector3f velInit, float massInit,float radiusInit);
	Body(Eigen::Vector3f posInit, float massInit, float radiusInit); 
	Eigen::Vector3f getPos();
	Eigen::Vector3f getVel();
	Eigen::Vector3f getAcc();
	float getMass();
	float getRadius();

	void setMass( Eigen:Vector3f newMass );
	void setRadius( Eigen::Vector3f newRadius );

	//Need to add the Sensor class

	void addSensor(Sensor newSensor);
	void addSensor(int placeAfter, Sensor newSensor);
	void reorderSensors(int sensorNo, int placeAfter);
	void removeSensor(int sensorNo);

	Sensor* getSensor(int sensorNo);
	void getSensorValue(int sensorNo);
	
	//Need to add the Thruster class

	void addThruster(Thruster newThruster);
	void addThruster(int placeAfter, Thruster newThruster);
	void reorderThrusters(int thrusterNo, int placeAfter);
	void removeThruster(int thrusterNo);

	void changeThrust(int thrusterNo, double percent);
	Eigen::Vector3f calculateThrustVector();
	Thruster* getThruster(int thrusterNo);


	//Add in Controllers later as well as Estimators
	//Need to define how state changes over time
	//Collisions? Later. Assume single, phasing body for now.
	//Need to set up resistive forces. Air, ground resistance? Gravity? I think those might just be in the world.
private:
	std::Vector<Sensor> Sensors;
	std::Vector<Thruster> Thrusters;
	Eigen::Vector3f position;
	Eigen::Vector3f velocity;
	Eigen::Vector3f acceleration;
	float radius;
	float mass;

		
}; 



#endif
