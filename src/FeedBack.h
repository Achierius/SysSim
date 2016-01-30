#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "Controller.h"

class FeedBack: public Controller{
public:
	virtual void getFeedback(Eigen::VectorXd input);	
protected:
	Eigen::VectorXd state;
	

}

#endif
