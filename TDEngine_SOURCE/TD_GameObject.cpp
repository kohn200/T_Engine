#include "TD_GameObject.h"
#include "TD_Input.h"
#include "TD_Time.h"

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
	const int speed = 100;

	if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
	{
		//m_X -= 0.01f;
		m_X -= speed * Time::GetDeltaTime();
	}
	if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
	{
		m_X += speed * Time::GetDeltaTime();
	}
	if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
	{
		m_Y -= speed * Time::GetDeltaTime();
	}
	if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
	{
		m_Y += speed * Time::GetDeltaTime();
	}

}

void GameObject::LateUpdate()
{

}

void GameObject::Render(HDC hdc)
{
	HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

	//HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	//HPEN OldPen = (HPEN)SelectObject(hdc, RedPen);

	Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

	SelectObject(hdc, OldBrush);
	DeleteObject(BlueBrush);

	//SelectObject(hdc, OldPen);
	//DeleteObject(RedPen);
}

void GameObject::SetPosition(float x, float y)
{
	m_X = x;
	m_Y = y;
}