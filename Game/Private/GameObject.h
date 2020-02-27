#pragma once
#include "Engine/Public/EngineTypes.h"
#include <string>

typedef unsigned int Hash;

class exEngineInterface;
class GameObjectHandle;

class GameObject
{

public:

	GameObject( exEngineInterface* pEngine, const exVector2& v2Position, exColor* color, Hash hash);
	~GameObject();

	virtual void Update( float fDeltaT ) = 0;

	virtual void Render() = 0;

	GameObjectHandle GetHandle();

	void Expire();

public:

	Hash					mHash;

	exEngineInterface*		mEngine;

	exVector2				mPosition;

	exColor*				mColor;

	bool					mExpiring;
};
