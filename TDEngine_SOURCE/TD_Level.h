#pragma once
#include "TD_Entity.h"

class GameObject;

class Level : public Entity
{
public:
	Level();
	~Level();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	
	void AddGameObject(GameObject* gameObject);
protected:
	vector<GameObject*> m_GameObjects;
};

