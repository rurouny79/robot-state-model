#ifndef STATEROOT_H_
#define STATEROOT_H_

#include "RobotState.h"

class StateRoot: public RobotState {
public:
	StateRoot(Robot* robot) :
			RobotState(robot) {
	}
	~StateRoot(void) {

	}
	virtual int StateStart(STATECHANGECODE eStateChangeCode) {
		return 0;
	}
	virtual int StateEnd(STATECHANGECODE eStateChangeCode) {
		return 0;
	}
	virtual int PreEventProcessing(Event* pMsg) {
		return 0;
	}
	virtual int PostEventProcessing(Event* pMsg) {
		return 0;
	}
	virtual int HandleBootingComplete(Event* pMsg) {
		return 0;
	}
	virtual int HandleCommandStart(Event* pMsg) {
		return 0;
	}
	virtual int HandleWorkingComplete(Event* pMsg) {
		return 0;
	}
	virtual int HandleGetError(Event* pMsg) {
		return 0;
	}
	virtual int HandleRecoverError(Event* pMsg) {
		return 0;
	}
	virtual int HandleCommandPowerOff(Event* pMsg) {
		return 0;
	}
};

#endif
