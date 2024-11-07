#pragma once
#include "CommonInclude.h"
#include "TD_Component.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	template <typename T>
	T* AddComponent()
	{
		T* comp = new T();
		comp->Initialize();
		comp->SetOwner(this);

		m_Components[(UINT)comp->GetComponentType()] = comp;
		//m_Components.push_back(comp);

		return comp;
	}

	template <typename T>
	T* GetComponent()
	{
		T* component = nullptr;

		for (Component* comp : m_Components)
		{
			component = dynamic_cast<T*>(comp);
			if (component)
				break;
		}

		return component;
	}

private:
	void initTransform();

private:
	vector<Component*> m_Components;
};

