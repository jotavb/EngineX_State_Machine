#include "FSMState_TrafficLightAlert.h"
#include "FSMState_TrafficLightStop.h"
#include "TrafficLight.h"
#include "Utils.h"
#include "FSM.h"

FSMState_TrafficLightAlert::FSMState_TrafficLightAlert(FSM* pFMS, TrafficLight* pTrafficLight)
	: FSMState_TrafficLightBase(pFMS, pTrafficLight)
	, mDuration( 2 )
{
}

FSMState_TrafficLightAlert::~FSMState_TrafficLightAlert()
{
}

void FSMState_TrafficLightAlert::OnEnter()
{
	mCounter = 0.0f;
	Utils::SetColorRGB(mTrafficLight->mAlertColor, 255, 255, 0, 255);
}

void FSMState_TrafficLightAlert::OnUpdate(float fDeltaT)
{
	mCounter += fDeltaT;
	if (mCounter >= mDuration)
	{
		mFSM->Next(new FSMState_TrafficLightStop(mFSM, mTrafficLight));
	}
}

void FSMState_TrafficLightAlert::OnExit()
{
	Utils::SetColorRGB(mTrafficLight->mAlertColor, 100, 100, 0, 255);
}

