#ifndef STATEMOVING_H_
#define STATEMOVING_H_

#include "StateRoot.h"

class StateMoving: public StateRoot {
public:
	StateMoving(Robot* robot) :
			StateRoot(robot) {
	}
};

#endif
