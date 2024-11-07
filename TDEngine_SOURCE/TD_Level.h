#pragma once
#include "TD_Entity.h"
#include "TD_Layer.h"


class Level : public Entity
{
public:
	Level();
	~Level();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject(GameObject* gameObject, const eLayerType type);

protected:
	vector<Layer*> m_Layers;

};

