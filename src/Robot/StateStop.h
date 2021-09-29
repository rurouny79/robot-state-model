#ifndef STATESTOP_H_
#define STATESTOP_H_

#include "StateRoot.h"

class StateStop: public StateRoot {
public:
	StateStop(Robot* robot) :
			StateRoot(robot) {
	}
};

#endif
