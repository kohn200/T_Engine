#pragma once
#include "..\\TDEngine_SOURCE\\TD_GameObject.h"

class Player : public GameObject
{
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

private:
};

