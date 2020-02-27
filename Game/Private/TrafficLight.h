#pragma once
#include "GameObject.h"

class FSM;

class TrafficLight : public GameObject
{
public:

	TrafficLight(exEngineInterface* pEngine, const exVector2& v2Position, exColor* pColor, Hash hash);
	~TrafficLight();

	virtual void Update(float fDeltaT) override;

	virtual void Render() override;

	exColor* mStopColor;

	exColor* mAlertColor;

	exColor* mGoColor;

private:

	FSM* mFSM;

	float mBoxWidth;

	float mBoxHeight;

	float mLightRadius;

	std::hash<std::string> s_hash;
};

