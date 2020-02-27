#pragma once

class FSM;

class FSMState
{

public:
	
	FSMState(FSM* pFSM);

	virtual ~FSMState();

	virtual void OnEnter() = 0;

	virtual void OnUpdate(float fDeltaT) = 0;

	virtual void OnExit() = 0;

protected:

	FSM* mFSM;

};