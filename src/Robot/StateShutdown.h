#ifndef STATESHUTDOWN_H_
#define STATESHUTDOWN_H_

#include "StateStop.h"

class StateShutdown: public StateStop {
public:
	StateShutdown(Robot* robot) :
			StateStop(robot) {
	}
};

#endif
