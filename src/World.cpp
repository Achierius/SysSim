#include "World.h"

World::Update(){
	for(auto itr = Bodies.begin(); itr != Bodies.end(); itr++){
		itr->Update(dT);
	}
}
World::addBody(Body newBody){
	Bodies.push_back(newBody);
