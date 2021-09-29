#ifndef STATEBOOTING_H_
#define STATEBOOTING_H_

#include "StateStop.h"

class StateBooting: public StateStop {
public:
	StateBooting(Robot* robot) :
			StateStop(robot) {
	}
};

#endif
