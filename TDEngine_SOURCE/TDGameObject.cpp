#include "TDGameObject.h"

GameObject::GameObject()
	: m_X(0.0f)
	, m_Y(0.0f)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_X -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_X += 0.01f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_Y -= 0.01f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_Y += 0.01f;
	}
}

void GameObject::LateUpdate()
{

}

void GameObject::Render(HDC hdc)
{
	HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

	Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

	SelectObject(hdc, OldBrush);
	DeleteObject(BlueBrush);

	HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN OldPen = (HPEN)SelectObject(hdc, RedPen);

	Ellipse(hdc, 800, 350, 1000, 550);

	SelectObject(hdc, OldPen);
	DeleteObject(RedPen);
}

void GameObject::SetPosition(float x, float y)
{
	m_X = x;
	m_Y = y;
}