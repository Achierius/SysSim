#ifndef _BODY_H
#define _BODY_H
#include <Eigen/Eigen/Dense>


class Body{
public:
	Body(Vector3f posInit, Vector3f velInt, Vector3f accInt, float massInit,float radiusInit);
	Body(Vector3f posInit, float massInit, float radiusInit); 
	Vector3f getPos();
	Vector3f getVel();
	Vector3f getAcc();
	float getMass();
	float getRadius();

	void setMass( Vector3f newMass );
	void setRadius( Vector3f newRadius );

	//Need to add the Sensor class

	void addSensor();
	void addSensor(int placeAfter);
	void reorderSensors(int sensorNo, int placeAfter);
	void removeSensor(int sensorNo);

	void getSensor(int sensorNo);
	void getSensorValue(int sensorNo);
	
	//Need to add the Thruster class

	void addThruster();
	void addThruster(int placeAfter);
	void reorderThrusters(int thrusterNo, int placeAfter);
	void removeThruster(int thrusterNo);

	void thrust(int thrusterNo, double percent);
	void getThruster(int thrusterNo);


	//Add in Controllers later as well as Estimators
	//Need to define how state changes over time
	//Collisions? Later. Assume single, phasing body for now.
	//Need to set up resistive forces. Air, ground resistance? Gravity? I think those might just be in the world.
private:
} 



#endif
