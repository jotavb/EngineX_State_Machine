//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//
#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include <vector>

typedef unsigned int Hash;

class GameObject;

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

public:

	exEngineInterface*			mEngine;

	bool						mRelease;

	GameObject*					mTrafficLight;

	std::vector<GameObject*>	mGameObjects;

	std::vector<GameObject*>	mGameObjectsToAdd;

private:

	std::hash<std::string> s_hash;
};
