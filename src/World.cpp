#include "World.h"
#include <iostream>
#include <cmath>

World::World(double initdT){
  if(initdT == 0){ dT = 0.02; }
  else {
    dT = (initdT < 0) ? initdT * -1 : initdT;
  }
}
void World::Update(){
	for(auto itr = Bodies.begin(); itr != Bodies.end(); itr++){
		(*itr)->Update(dT);
	}
}
void World::addBody(std::unique_ptr<Body> newBody){
	Bodies.push_back(std::move(newBody));
}
void World::removeBody(int numBody){
	Bodies.erase(Bodies.begin()+(numBody-1));
}

