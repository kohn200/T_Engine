#pragma once
#include "..\\TDEngine_SOURCE\\TD_LevelManager.h"
#include "TD_PlayLevel.h"

//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\TDEngine_Window.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\TDEngine_Window.lib")
//#endif

namespace TD
{
	void LoadLevels()
	{
		LevelManager::CreateLevel<PlayLevel>(L"PlayLevel");

		//LevelManager::CreateLevel<PlayLevel>(L"TitleLevel");

		LevelManager::LoadLevel(L"PlayLevel");
	}
}
