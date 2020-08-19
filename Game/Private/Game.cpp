#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Utils.h"
#include "GameObject.h"
#include "TrafficLight.h"
#include <time.h>
#include <algorithm>

const char* gWindowName = "Traffic Light";

MyGame::MyGame()
	: mEngine( nullptr )
	, mRelease( false )
{
}

MyGame::~MyGame()
{
	delete mTrafficLight;
}

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	srand( (unsigned int)time( 0 ) );

	// Create the Traffic Light 
	exVector2 origin;
	origin.x = 200.0f;
	origin.y = 490.0f;
	Hash TF_hash = s_hash("TrafficLight");
	mTrafficLight = new TrafficLight(mEngine, origin, Utils::GetColorRGB(255, 255, 255, 255), TF_hash);
	mGameObjects.push_back(mTrafficLight);
}

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mRelease = pState[SDL_SCANCODE_SPACE];
}

void MyGame::Run( float fDeltaT )
{
	// Game object management

	// Update objects first
	for ( GameObject* pGameObject : mGameObjects )
	{
		if ( !pGameObject->mExpiring )
		{
			pGameObject->Update( fDeltaT );
		}
	}

	// Deal with expired objects first
	std::vector<GameObject*> gameObjectsToRemove;

	for ( GameObject* pGameObject : mGameObjects )
	{
		if ( pGameObject->mExpiring )
		{
			gameObjectsToRemove.push_back( pGameObject );
		}
	}

	for ( GameObject* pGameObject : gameObjectsToRemove )
	{
		mGameObjects.erase( std::remove( mGameObjects.begin(), mGameObjects.end(), pGameObject ), mGameObjects.end() );
		delete pGameObject;
	}
	
	// Add all new objects
	for ( GameObject* pGameObject : mGameObjectsToAdd )
	{
		mGameObjects.push_back( pGameObject );
	}

	mGameObjectsToAdd.clear();

	// Now render everything
	for ( GameObject* pGameObject : mGameObjects )
	{
		pGameObject->Render();
	}
}
