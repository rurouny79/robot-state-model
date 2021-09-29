#include "Robot/Robot.h"

class ServiceContext {
public:
	ServiceContext(void) {
		robot = new Robot(this);
		robot->ChangeState(eSTATE_BOOTING, eSTATECHANGECODE_NULL);
	}

	~ServiceContext(void) {
		delete robot;
	}

	void ReceiveMessage(Event *event) {
		robot->ProcessEvent(event);
	}

private:
	Robot *robot;
};
