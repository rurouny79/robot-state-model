#include "Robot.h"
#include "StateBooting.h"
#include "StateReady.h"
#include "StateWorking.h"
#include "StateError.h"
#include "StateShutdown.h"
#include "../Event/Event.h"
#include "../Manager/RobotDataManager.h"
#include "../Manager/DisplayManager.h"
#include "../Manager/SoundManager.h"
#include "RobotState.h"

Robot::Robot(ServiceContext* context) {
	mStateBooting = new StateBooting(this);
	mStateReady = new StateReady(this);
	mStateWorking = new StateWorking(this);
	mStateError = new StateError(this);
	mStateShutdown = new StateShutdown(this);

	mCurrentState = 0;

	mServiceContext = context;

	mRobotDataManager = new RobotDataManager(this);
	mDisplayManager = new DisplayManager(this);
	mSoundManager = new SoundManager(this);
}

Robot::~Robot(void) {
	delete mStateBooting;
	delete mStateReady;
	delete mStateWorking;
	delete mStateError;
	delete mStateShutdown;

	delete mRobotDataManager;
	delete mDisplayManager;
	delete mSoundManager;
}

void Robot::ChangeState(STATE eState, STATECHANGECODE eStateChangeCode) {
	if (mCurrentState)
		mCurrentState->StateEnd(eStateChangeCode);

	switch (eState) {
	case eSTATE_BOOTING:
		mCurrentState = mStateBooting;
		break;
	case eSTATE_READY:
		mCurrentState = mStateReady;
		break;
	case eSTATE_WORKING:
		mCurrentState = mStateWorking;
		break;
	case eSTATE_ERROR:
		mCurrentState = mStateError;
		break;
	case eSTATE_SHUTDOWN:
		mCurrentState = mStateShutdown;
		break;
	default:
		break;
	}

	mCurrentState->StateStart(eStateChangeCode);
}

void Robot::ProcessEvent(Event* event) {
	if (mCurrentState->PreEventProcessing(event) < 0)
		return;

	switch (event->GetEventCode()) {
	case eEVENT_BOOTING_COMPLETE:
		mCurrentState->HandleBootingComplete(event);
		break;
	case eEVENT_COMMAND_START:
		mCurrentState->HandleCommandStart(event);
		break;
	case eEVENT_WORKING_COMPLETE:
		mCurrentState->HandleWorkingComplete(event);
		break;
	case eEVENT_GET_ERROR:
		mCurrentState->HandleGetError(event);
		break;
	case eEVENT_RECOVER_ERROR:
		mCurrentState->HandleRecoverError(event);
		break;
	case eEVENT_COMMAND_POWEROFF:
		mCurrentState->HandleCommandPowerOff(event);
		break;
	default:
		break;
	}

	mCurrentState->PostEventProcessing(event);
}
