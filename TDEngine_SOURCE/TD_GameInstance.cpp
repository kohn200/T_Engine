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
	// 오른쪽 키를 입력 -> x가 플러스
	// 왼쪽 키를 입력 -> x가 마이너스

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
		//// 키보드 입력으로 바뀐 플레이어의 위치 세팅
		//m_Player.SetPosition(x, y);
		// 위의 코드는 GameObject의 Update()함수에 있는 것이 바람직한 거 같다.

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
