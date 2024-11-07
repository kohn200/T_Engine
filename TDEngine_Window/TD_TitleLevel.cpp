#include "TD_TitleLevel.h"
#include "TD_PlayLevel.h"
#include "TD_LevelManager.h"
#include "TD_Input.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Initialize()
{
	Level::Initialize();
}

void TitleLevel::Update()
{
	Level::Update();
}

void TitleLevel::LateUpdate()
{
	Level::LateUpdate();

	if (Input::GetKeyDown(eKeyCode::N))
	{
		LevelManager::LoadLevel(L"PlayLevel");
	}
}

void TitleLevel::Render(HDC hdc)
{
	Level::Render(hdc);

	wchar_t str[50] = L"Title Level";
	TextOut(hdc, 750, 0, str, 11);
}

void TitleLevel::OnEnter()
{
}

void TitleLevel::OnExit()
{
}
