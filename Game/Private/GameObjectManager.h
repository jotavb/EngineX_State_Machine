#pragma once
#include "HashMap.h"
#include "Singleton.h"
typedef unsigned int Hash;

class GameObject;

class GameObjectManager : public Singleton<GameObjectManager>
{
public:

	friend class Singleton<GameObjectManager>;

	void Register(GameObject* pGO);

	void Unregister(GameObject* pGO);

	bool Exists(Hash hash) const;

	GameObject* Lookup(Hash hash);

	const GameObject* Lookup(Hash hash) const;

private:
	HashMap<GameObject*, 256> mMap;
};

GameObjectManager*Singleton<GameObjectManager>::mInstance = nullptr;
