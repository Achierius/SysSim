#include "World.h"

World::World(double initdT){
	dT = initdT = 0 ? 0.001 : abs(initdT);
}
World::Update(){
	for(auto itr = Bodies.begin(); itr != Bodies.end(); itr++){
		itr->Update(dT);
	}
}
World::addBody(Body newBody){
	Bodies.push_back(newBody);
}
World::getBody(int numBody){ //Add guards on this
	return Bodies[numBody];
}
World::removeBody(int numBody){//Same
	Bodies.erase(numBody);
}

