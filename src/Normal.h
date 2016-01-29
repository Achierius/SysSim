#include <tuple>
namespace Norm{
	typedef std::tuple<float, float> PDF; //mu, sigma

	float CDF(PDF pdf, float min, float max); //Gives the area / cumulative probability within two bounds on a normal curve
	float getValue(PDF pdf, float value); //Gives the value of the given normal distribution at any point
	float invNorm(PDF pdf, float percent) //Starts from centre; if negative, it goes left, if positive, goes right. Determines what position on the curve (starting from the middle) will give you 'percent' area
}
