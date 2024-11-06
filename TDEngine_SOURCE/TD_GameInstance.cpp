#include "TD_GameInstance.h"
#include "TD_Input.h"
#include "TD_Time.h"

GameInstance::GameInstance()
	: m_Hwnd(nullptr)
	, m_Hdc(nullptr)
	, m_Width(0)
	, m_Height(0)
	, m_BackHdc(nullptr)
	, m_BackBuffer(nullptr)
{

}

GameInstance::~GameInstance()
{

}

void GameInstance::Initialize(HWND hwnd, UINT width, UINT height)
{
	m_Hwnd = hwnd;
	m_Hdc = GetDC(hwnd);

	// BackBuffer(BackDC) �۾�
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	m_Width = rect.right - rect.left;
	m_Height = rect.bottom - rect.top;
	SetWindowPos(m_Hwnd, nullptr, 0, 0, m_Width, m_Height, 0);
	
	ShowWindow(m_Hwnd, true);

	// ������ �ػ󵵿� �´� �����(��ȭ��) ����
	m_BackBuffer = CreateCompatibleBitmap(m_Hdc, width, height);

	// ����۸� ����ų DC ����
	m_BackHdc = CreateCompatibleDC(m_Hdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
	DeleteObject(oldBitmap);


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
	Input::Update();
	Time::Update();

	m_Player.Update();
}

void GameInstance::LateUpdate()
{

}

void GameInstance::Render()
{
	Rectangle(m_BackHdc, 0, 0, 1600, 900);

	Time::Render(m_BackHdc);
	m_Player.Render(m_BackHdc);
	
	// BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
	BitBlt(m_Hdc, 0, 0, m_Width, m_Height, m_BackHdc, 0, 0, SRCCOPY);
}
