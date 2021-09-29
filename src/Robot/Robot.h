#ifndef ROBOT_H_
#define ROBOT_H_

class ServiceContext;
class RobotDataManager;
class DisplayManager;
class SoundManager;
class Event;
class RobotState;
class StateBooting;
class StateReady;
class StateWorking;
class StateError;
class StateShutdown;

enum STATE {
	eSTATE_NULL = 0, //
	eSTATE_BOOTING, //
	eSTATE_READY, //
	eSTATE_WORKING, //
	eSTATE_ERROR, //
	eSTATE_SHUTDOWN
};

enum STATECHANGECODE {
	eSTATECHANGECODE_NULL = 0, //
};

class Robot {
private:
	RobotState* mCurrentState;

	StateBooting* mStateBooting;
	StateReady* mStateReady;
	StateWorking* mStateWorking;
	StateError* mStateError;
	StateShutdown* mStateShutdown;

	ServiceContext* mServiceContext;

	RobotDataManager* mRobotDataManager;
	DisplayManager* mDisplayManager;
	SoundManager* mSoundManager;

public:
	Robot(ServiceContext* serviceContext);
	~Robot(void);

	void ChangeState(STATE eState, STATECHANGECODE eStateChangeCode);
	void ProcessEvent(Event* poEvent);

	ServiceContext* GetServiceContext(void) {
		return mServiceContext;
	}
	RobotDataManager* GetRobotDataManager(void) {
		return mRobotDataManager;
	}
	DisplayManager* GetDisplayManager(void) {
		return mDisplayManager;
	}
	SoundManager* GetSoundManager(void) {
		return mSoundManager;
	}
};

#endif
