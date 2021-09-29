#ifndef STATEERROR_H_
#define STATEERROR_H_

#include "StateStop.h"

class StateError: public StateStop {
public:
	StateError(Robot* robot) :
			StateStop(robot) {
	}
};

#endif
