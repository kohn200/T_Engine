#include "TD_GameObject.h"
#include "TD_Input.h"
#include "TD_Time.h"
#include "TD_Transform.h"

GameObject::GameObject()
{
	initTransform();
}

GameObject::~GameObject()
{
	for (Component* comp : m_Components)
	{
		delete comp;
		comp = nullptr;
	}
}

void GameObject::Initialize()
{
	for (Component* comp : m_Components)
	{
		comp->Initialize();
	}
}

void GameObject::Update()
{
	for (Component* comp : m_Components)
	{
		comp->Update();
	}
}

void GameObject::LateUpdate()
{
	for (Component* comp : m_Components)
	{
		comp->LateUpdate();
	}
}

void GameObject::Render(HDC hdc)
{
	for (Component* comp : m_Components)
	{
		comp->Render(hdc);
	}
	
	//// 파랑 브러쉬 생성
	//HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	//// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
	//HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

	////HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	////HPEN OldPen = (HPEN)SelectObject(hdc, RedPen);
	////SelectObject(hdc, OldPen);
	//
	////Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);
	//Ellipse(hdc, m_X, m_Y, m_X + 100.f, m_Y + 100.f);

	//SelectObject(hdc, OldBrush);
	//DeleteObject(BlueBrush);
	////DeleteObject(RedPen);
}

void GameObject::initTransform()
{
	AddComponent<Transform>();
}