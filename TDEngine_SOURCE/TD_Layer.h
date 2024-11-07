#pragma once
#include "TD_Entity.h"
#include "CommonInclude.h"
#include "TD_GameObject.h"

class Layer : public Entity
{
public:
	Layer();
	~Layer();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void AddGameObject(GameObject* gameObject);

private:
	//eLayerType m_Type;
	vector<GameObject*> m_GameObjects;

};

