#include <tuple>
namespace Norm{
	typedef std::tuple<float, float> PDF; //mu, sigma
	float CDF(PDF pdf, float min, float max);
	float getValue(PDF pdf, float value);
}
