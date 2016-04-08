#include "Function.h"

class Sine : Function{
public:
  constexpr static double pi = 3.1415926535;

  double operator()(double input) override;

  Sine(double amplitude, double period, double phase);
  Sine(double amplitude, double period);
  Sine(double amplitude);
  Sine();
private:
  double amplitude;
  double period;
  double phase;

  double calculate(double input) override;
};
