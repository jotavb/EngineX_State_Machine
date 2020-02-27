#pragma once
#include "FSMState.h"

class FSM;
class TrafficLight;

class FSMState_TrafficLightBase : public FSMState
{
public:	

	FSMState_TrafficLightBase(FSM* pFMS, TrafficLight* pTrafficLight) 
		: FSMState(pFMS)
		,mTrafficLight ( pTrafficLight )
	{
	}

	~FSMState_TrafficLightBase() override
	{
	}


protected:

	TrafficLight* mTrafficLight;

};