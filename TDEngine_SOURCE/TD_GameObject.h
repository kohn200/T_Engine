#pragma once
#include "CommonInclude.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	float GetPositionX() { return m_X; }
	float GetPositionY() { return m_Y; }

	void SetPosition(float x, float y);

private:
	float m_X;
	float m_Y;
};

