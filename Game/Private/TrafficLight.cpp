#include "Engine/Public/EngineInterface.h"
#include "FSMState_TrafficLightAlert.h"
#include "TrafficLight.h"
#include "FSM.h"
#include "Utils.h"

TrafficLight::TrafficLight(exEngineInterface* pEngine, const exVector2& v2Position, exColor* pColor, Hash hash) 
	: GameObject( pEngine, v2Position, pColor, hash )
	, mBoxWidth( 100.0f )
	, mBoxHeight( 200.0f )
	, mLightRadius( 25.0f )	
	, mStopColor( Utils::GetColorRGB(100, 0, 0, 255) )
	, mAlertColor( Utils::GetColorRGB(100, 100, 0, 255) )
	, mGoColor( Utils::GetColorRGB(0, 100, 0, 255) )
{
	mFSM = new FSM();
	mFSM->Initialize(new FSMState_TrafficLightAlert(mFSM, this));
}

TrafficLight::~TrafficLight()
{
	delete mFSM;
	delete mGoColor; 
	delete mStopColor;
	delete mAlertColor;
}

void TrafficLight::Update(float fDeltaT)
{
	mFSM->Update(fDeltaT);
}

void TrafficLight::Render()
{
	exVector2 p1{ mPosition.x - mBoxWidth / 2, mPosition.y + mBoxHeight / 2 };
	exVector2 p2{ mPosition.x + mBoxWidth / 2, mPosition.y - mBoxHeight / 2 };
	mEngine->DrawBox(p1, p2, *mColor, 1);

	mEngine->DrawCircle(mPosition, mLightRadius, *mAlertColor, 1);

	exVector2 p3 { mPosition.x, mPosition.y - 60.0f };
	mEngine->DrawCircle(p3, mLightRadius, *mStopColor, 1);

	exVector2 p4{ mPosition.x, mPosition.y + 60.0f };
	mEngine->DrawCircle(p4, mLightRadius, *mGoColor, 1);
}