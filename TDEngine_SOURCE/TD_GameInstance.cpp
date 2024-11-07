#include "TD_GameInstance.h"
#include "TD_Input.h"
#include "TD_Time.h"
#include "TD_LevelManager.h"

GameInstance::GameInstance()
	: m_Hwnd(nullptr)
	, m_Hdc(nullptr)
	, m_Width(0)
	, m_Height(0)
	, m_BackHdc(nullptr)
	, m_BackBuffer(nullptr)
	//, m_Levels{}
{

}

GameInstance::~GameInstance()
{

}

void GameInstance::Initialize(HWND hwnd, UINT width, UINT height)
{
	adjustWindowRect(hwnd, width, height);

	createBuffer(width, height);

	initializeEtc();

	LevelManager::Initialize();
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
	LevelManager::Update();
}

void GameInstance::LateUpdate()
{
	LevelManager::LateUpdate();
}

void GameInstance::Render()
{
	clearRenderTarget();

	Time::Render(m_BackHdc);
	LevelManager::Render(m_BackHdc);

	copyRenderTarget(m_Hdc, m_BackHdc);
}

void GameInstance::clearRenderTarget()
{
	// 상단에 줄 표시되어 있는거 지우기
	Rectangle(m_BackHdc, -1, -1, 1601, 901);
}

void GameInstance::copyRenderTarget(HDC source, HDC dest)
{
	// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
	BitBlt(source, 0, 0, m_Width, m_Height, dest, 0, 0, SRCCOPY);
}

void GameInstance::adjustWindowRect(HWND hwnd, UINT width, UINT height)
{
	m_Hwnd = hwnd;
	m_Hdc = GetDC(hwnd);

	// BackBuffer(BackDC) 작업
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	m_Width = rect.right - rect.left;
	m_Height = rect.bottom - rect.top;
	SetWindowPos(m_Hwnd, nullptr, 0, 0, m_Width, m_Height, 0);

	ShowWindow(m_Hwnd, true);
}

void GameInstance::createBuffer(UINT width, UINT height)
{
	// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
	m_BackBuffer = CreateCompatibleBitmap(m_Hdc, width, height);

	// 백버퍼를 가르킬 DC 생성
	m_BackHdc = CreateCompatibleDC(m_Hdc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_BackBuffer);
	DeleteObject(oldBitmap);
}

void GameInstance::initializeEtc()
{
	Input::Initialize();
	Time::Initialize();
}