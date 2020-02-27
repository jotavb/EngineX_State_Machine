#pragma once
#include "FSMState_TrafficLightBase.h"

class FSM;
class TrafficLight;

class FSMState_TrafficLightStop : public FSMState_TrafficLightBase
{
public:

	FSMState_TrafficLightStop(FSM* pFMS, TrafficLight* pTrafficLight);

	~FSMState_TrafficLightStop();

	virtual void OnEnter() override;

	virtual void OnUpdate(float fDeltaT) override;

	virtual void OnExit() override;
	

private:

	float mDuration;

	float mCounter;
};