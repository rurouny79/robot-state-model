#ifndef STATEWORKING_H_
#define STATEWORKING_H_

#include "StateMoving.h"

class StateWorking: public StateMoving {
public:
	StateWorking(Robot* robot) :
			StateMoving(robot) {
	}
};

#endif
