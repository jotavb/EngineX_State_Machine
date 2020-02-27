#pragma once
#include "FSMState_TrafficLightBase.h"

class FSM;
class TrafficLight;

class FSMState_TrafficLightAlert : public FSMState_TrafficLightBase
{
public:

	FSMState_TrafficLightAlert(FSM* pFMS, TrafficLight* pTrafficLight);

	~FSMState_TrafficLightAlert();

	virtual void OnEnter() override;

	virtual void OnUpdate(float fDeltaT) override;

	virtual void OnExit() override;


private:

	float mDuration;

	float mCounter;
};