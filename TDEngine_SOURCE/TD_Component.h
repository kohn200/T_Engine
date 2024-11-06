#pragma once
#include "TD_Entity.h"

class GameObject;

class Component : public Entity
{
public:
	Component();
	~Component();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(GameObject* gameObject) { m_Owner = gameObject; }
	GameObject* GetOwner() { return m_Owner; }

private:
	GameObject* m_Owner;
};

