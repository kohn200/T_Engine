#pragma once
#include "TD_Entity.h"
#include "TD_Component.h"

using namespace math;

class Transform : public Component
{
public:
	Transform();
	~Transform();

	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	void SetPos(Vector2 pos) 
	{
		m_Position.x = pos.x;
		m_Position.y = pos.y;
	}

	Vector2 GetPos() { return m_Position; }

private:
	Vector2 m_Position;
};

