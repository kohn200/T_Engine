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
	if (Input::GetKey(eKeyCode::SpaceBar))
	{

	}
}

void GameObject::LateUpdate()
{

}

void GameObject::Render(HDC hdc)
{
	// 파랑 브러쉬 생성
	HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

	//HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	//HPEN OldPen = (HPEN)SelectObject(hdc, RedPen);
	//SelectObject(hdc, OldPen);
	
	//Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);
	Ellipse(hdc, m_X, m_Y, m_X + 100.f, m_Y + 100.f);

	SelectObject(hdc, OldBrush);
	DeleteObject(BlueBrush);
	//DeleteObject(RedPen);
}

void GameObject::SetPosition(float x, float y)
{
	m_X = x;
	m_Y = y;
}