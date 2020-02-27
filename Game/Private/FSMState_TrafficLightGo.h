#pragma once
#include "FSMState_TrafficLightBase.h"

class FSM;
class TrafficLight;

class FSMState_TrafficLightGo : public FSMState_TrafficLightBase
{
public:

	FSMState_TrafficLightGo(FSM* pFMS, TrafficLight* pTrafficLight);

	~FSMState_TrafficLightGo();

	virtual void OnEnter() override;

	virtual void OnUpdate(float fDeltaT) override;

	virtual void OnExit() override;


private:

	float mDuration;

	float mCounter;
};