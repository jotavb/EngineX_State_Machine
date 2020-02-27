#include "FSMState_TrafficLightAlert.h"
#include "FSMState_TrafficLightGo.h"
#include "TrafficLight.h"
#include "Utils.h"
#include "FSM.h"

FSMState_TrafficLightGo::FSMState_TrafficLightGo(FSM* pFMS, TrafficLight* pTrafficLight)
	: FSMState_TrafficLightBase(pFMS, pTrafficLight)
	, mDuration( 5 )
{
}

FSMState_TrafficLightGo::~FSMState_TrafficLightGo()
{
}

void FSMState_TrafficLightGo::OnEnter()
{
	mCounter = 0.0f;
	Utils::SetColorRGB(mTrafficLight->mGoColor, 0, 255, 0, 255);
}

void FSMState_TrafficLightGo::OnUpdate(float fDeltaT)
{
	mCounter += fDeltaT;
	if (mCounter >= mDuration)
	{
		mFSM->Next(new FSMState_TrafficLightAlert(mFSM, mTrafficLight));
	}
}

void FSMState_TrafficLightGo::OnExit()
{
	Utils::SetColorRGB(mTrafficLight->mGoColor, 0, 100, 0, 255);
}

