#ifndef _BODY_H
#define _BODY_H
#include <Eigen/Eigen/Dense>
#include <vector>
#include <memory>
#include "Thruster.h"
#include "Sensor.h"

class Sensor;

class Body{
public:
	Body(Eigen::Vector3d posInit, Eigen::Vector3d velInit, double massInit,double radiusInit);
	Body(Eigen::Vector3d posInit, double massInit, double radiusInit);
	Eigen::Vector3d getPos();
	Eigen::Vector3d getVel();
	Eigen::Vector3d getAcc();
	double getMass();
	double getRadius();

	void setMass( double newMass );
	void setRadius( double newRadius );

	//Need to add the Sensor class

	void addSensor(std::unique_ptr<Sensor> newSensor);
	void addSensor(int placeAfter, std::unique_ptr<Sensor> newSensor);
	void reorderSensors(int sensorNo, int placeAfter);
	void removeSensor(int sensorNo);

  std::unique_ptr<Sensor> getSensor(int sensorNo);
	double getSensorValue(int sensorNo);

	//Need to add the Thruster class

	void addThruster(std::unique_ptr<Thruster> newThruster);
	void addThruster(int placeAfter, std::unique_ptr<Thruster> newThruster);
	void reorderThrusters(int thrusterNo, int placeAfter);
	void removeThruster(int thrusterNo);

	void changeThrust(int thrusterNo, double percent);
	Eigen::Vector3d calculateThrustVector();
  std::unique_ptr<Thruster> getThruster(int thrusterNo);

	void Update(double dt);

	friend class Sensor;
	//Add in Controllers later as well as Estimators
	//Need to define how state changes over time
	//Collisions? Later. Assume single, phasing body for now.
	//Need to set up resistive forces. Air, ground resistance? Gravity? I think those might just be in the world.
private:
	std::vector< std::unique_ptr<Sensor> > Sensors; //http://stackoverflow.com/questions/27773640/c-passing-a-list-of-a-class-with-elements-of-a-subclass
	std::vector< std::unique_ptr<Thruster> > Thrusters;
	Eigen::Vector3d position;
	Eigen::Vector3d velocity;
	Eigen::Vector3d acceleration;
	double radius;
	double mass;


};



#endif
