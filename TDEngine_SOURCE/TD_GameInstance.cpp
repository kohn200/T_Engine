#include "TD_GameInstance.h"
#include "TD_Input.h"
#include "TD_Time.h"

GameInstance::GameInstance()
	: m_Hwnd(nullptr)
	, m_Hdc(nullptr)
{

}

GameInstance::~GameInstance()
{

}

void GameInstance::Initialize(HWND hwnd)
{
	m_Hwnd = hwnd;
	m_Hdc = GetDC(hwnd);

	m_Player.SetPosition(0.f, 0.f);
	Input::Initialize();
	Time::Initialize();
}

void GameInstance::Run()
{
	Update();
	LateUpdate();
	Render();
}

void GameInstance::Update()
{
	// ������ Ű�� �Է� -> x�� �÷���
	// ���� Ű�� �Է� -> x�� ���̳ʽ�

	//float x = m_Player.GetPositionX();
		//float y = m_Player.GetPositionY();
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01;
		//}
		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01;
		//}
		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01;
		//}
		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01;
		//}
		//// Ű���� �Է����� �ٲ� �÷��̾��� ��ġ ����
		//m_Player.SetPosition(x, y);
		// ���� �ڵ�� GameObject�� Update()�Լ��� �ִ� ���� �ٶ����� �� ����.

	Input::Update();
	Time::Update();

	m_Player.Update();
}

void GameInstance::LateUpdate()
{

}

void GameInstance::Render()
{
	Time::Render(m_Hdc);
	m_Player.Render(m_Hdc);
}
