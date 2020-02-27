#include "GameObjectHandle.h"
#include "GameObjectManager.h"

bool GameObjectHandle::IsValid() const 
{
	return GameObjectManager::Get()->Exists(mHash);
}

GameObject* GameObjectHandle::Get() const
{
	return GameObjectManager::Get()->Lookup(mHash);
}