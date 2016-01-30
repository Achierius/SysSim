#include "Normal.h"
#include <iostream>

int main(){
	std::cout<<Norm::CDF(Norm::nDist,0,1)<<std::endl<<Norm::CDF(Norm::nDist, 0, Norm::invNorm(std::make_tuple(0,1),0.34))<<std::endl;
	return 0;
}
