#pragma once
#include "TD_Entity.h"

class GameObject;

class Component : public Entity
{
public:
	Component(eComponentType type);
	~Component();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void SetOwner(GameObject* gameObject) { m_Owner = gameObject; }
	GameObject* GetOwner() { return m_Owner; }

	eComponentType GetComponentType() { return m_ComponentType; }

private:
	GameObject* m_Owner;
	eComponentType m_ComponentType;
};

