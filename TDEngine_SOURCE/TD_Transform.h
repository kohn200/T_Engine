#pragma once
#include "TD_Entity.h"
#include "TD_Component.h"

struct Pos
{
	int mX;
	int mY;
};

class Transform : public Component
{
public:
	Transform();
	~Transform();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	void SetPos(int x, int y) 
	{
		m_X = x;
		m_Y = y;
	}

	int GetX() { return m_X; }
	int GetY() { return m_Y; }

private:
	int m_X;
	int m_Y;
};

