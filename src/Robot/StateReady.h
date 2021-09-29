#ifndef STATESTANDBY_H_
#define STATESTANDBY_H_

#include "StateStop.h"

class StateReady: public StateStop {
public:
	StateReady(Robot* robot) :
			StateStop(robot) {
	}
};

#endif
