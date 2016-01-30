#include <tuple>
namespace Norm{
	typedef std::tuple<float, float> PDF; //mu, sigma

	template <typename T> int sgn(T val);
	bool fuzzyCompare(float num1, float num2, float absoluteTolerance);

	float CDF(PDF pdf, float min, float max); //Gives the area / cumulative probability within two bounds on a normal curve
	float getValue(PDF pdf, float value); //Gives the value of the given normal distribution at any point
	float invNorm(PDF pdf, float percent); //Starts from centre; if negative, it goes left, if positive, goes right. Determines what position on the curve (starting from the middle) will give you 'percent' area
	
	const PDF nDist = std::make_tuple(0,1);
}
