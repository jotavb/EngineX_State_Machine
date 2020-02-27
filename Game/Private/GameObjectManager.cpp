#include "GameObjectManager.h"

void GameObjectManager::Register(GameObject* pGO)
{
	mMap.InsertNoCheck(pGO);
}

void GameObjectManager::Unregister(GameObject* pGO)
{
	mMap.Delete(pGO);
}

bool GameObjectManager::Exists(Hash hash) const
{
	return (mMap.Find(hash) != nullptr);
}

GameObject* GameObjectManager::Lookup(Hash hash)
{
	return mMap.Find(hash);
}

const GameObject* GameObjectManager::Lookup(Hash hash) const
{
	return mMap.Find(hash);
}