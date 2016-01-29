#include <iostream>
#include "Sensor.h"
#include "Thruster.h"
#include "Body.h"

#include <Eigen/Eigen/Dense>

using namespace Eigen;

int main(){
	Body bod(Vector3d(0,0,0),Vector3d(0,0.5,0.1),2,1);
	for(int i = 0; i < 100; i++){
		bod.Update(0.01);
		std::cout<<bod.getPos()<<std::endl;
	}
}

