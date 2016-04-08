#ifndef __SYSSIM_FUNCTION_H
#define __SYSSIM_FUNCTION_H

class Function {
public:
  virtual double operator()(double input) = 0;
private:
  virtual double calculate(double input) = 0;
};

#endif//__SYSSIM_FUNCTION_H
