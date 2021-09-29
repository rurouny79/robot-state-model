#ifndef EVENT_H_
#define EVENT_H_

enum eEVENT {
	eEVENT_UNKNOWN, //
	eEVENT_BOOTING_COMPLETE, //
	eEVENT_COMMAND_START, //
	eEVENT_GET_ERROR, //
	eEVENT_RECOVER_ERROR, //
	eEVENT_WORKING_COMPLETE, //
	eEVENT_COMMAND_POWEROFF,
};

class Event {
public:
	Event(void);
	eEVENT GetEventCode(void) {
		return eEVENT_UNKNOWN;
	}
};

#endif
