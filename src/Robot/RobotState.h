#ifndef ROBOTSTATE_H_
#define ROBOTSTATE_H_

class RobotState {
private:
	Robot* mRobot;

protected:
	int mStateChangeCode;

public:
	RobotState(Robot* poRobot) {
		mRobot = poRobot;
		mStateChangeCode = 0;
	}
	virtual ~RobotState(void) {
	}

	Robot* GetRobot(void) {
		return mRobot;
	}

	virtual int StateStart(STATECHANGECODE eStateChangeCode) = 0;
	virtual int StateEnd(STATECHANGECODE eStateChangeCode) = 0;

	virtual int PreEventProcessing(Event* event) = 0;
	virtual int PostEventProcessing(Event* event) = 0;

	virtual int HandleBootingComplete(Event* event) = 0;
	virtual int HandleCommandStart(Event* event) = 0;
	virtual int HandleWorkingComplete(Event* event) = 0;
	virtual int HandleGetError(Event* event) = 0;
	virtual int HandleRecoverError(Event* event) = 0;
	virtual int HandleCommandPowerOff(Event* event) = 0;
};

#endif
