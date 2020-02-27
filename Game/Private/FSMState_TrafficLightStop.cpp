#include "FSMState_TrafficLightStop.h"
#include "FSMState_TrafficLightGo.h"
#include "TrafficLight.h"
#include "Utils.h"
#include "FSM.h"

FSMState_TrafficLightStop::FSMState_TrafficLightStop(FSM* pFMS, TrafficLight* pTrafficLight)
	: FSMState_TrafficLightBase ( pFMS, pTrafficLight )
	, mDuration ( 5 )
{
}

FSMState_TrafficLightStop::~FSMState_TrafficLightStop() 
{
}

void FSMState_TrafficLightStop::OnEnter()
{
	mCounter = 0.0f;
	Utils::SetColorRGB(mTrafficLight->mStopColor, 255, 0, 0, 255);
}

void FSMState_TrafficLightStop::OnUpdate(float fDeltaT)
{
	mCounter += fDeltaT;
	if (mCounter >= mDuration)
	{
		mFSM->Next(new FSMState_TrafficLightGo(mFSM, mTrafficLight));
	}
}

void FSMState_TrafficLightStop::OnExit()
{
	Utils::SetColorRGB(mTrafficLight->mStopColor, 100, 0, 0, 255);
}

