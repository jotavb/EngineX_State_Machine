#include "Game/Private/GameObject.h"
#include "GameObjectManager.h"
#include "GameObjectHandle.h"
#include "Engine/Public/EngineInterface.h"

GameObject::GameObject( exEngineInterface* pEngine, const exVector2& v2Position, exColor* color, Hash hash)
	: mEngine( pEngine )
	, mPosition( v2Position )
	, mColor( color )
	, mHash( hash )
	, mExpiring( false )
{
	GameObjectManager::Get()->Register(this);
}

GameObject::~GameObject()
{
	GameObjectManager::Get()->Unregister(this);
	delete mColor;
}

void GameObject::Expire()
{
	mExpiring = true;
}

GameObjectHandle GameObject::GetHandle()
{
	GameObjectHandle temp;
	temp.mHash = mHash;
	return temp;
}
