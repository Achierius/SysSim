#include <tuple>
namespace Norm{
	typedef std::tuple<double, double> PDF; //mu, sigma

	template <typename T> int sgn(T val);
	bool fuzzyCompare(double num1, double num2, double absoluteTolerance);

	double CDF(PDF pdf, double min, double max); //Gives the area / cumulative probability within two bounds on a normal curve
	double getValue(PDF pdf, double value); //Gives the value of the given normal distribution at any point
	double invNorm(PDF pdf, double percent); //Starts from centre; if negative, it goes left, if positive, goes right. Determines what position on the curve (starting from the middle) will give you 'percent' area
	
	const PDF nDist = std::make_tuple(0,1);
}
