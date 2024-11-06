#include "TD_LevelManager.h"
#include "TD_Level.h"

map<wstring, Level*> LevelManager::m_Levels = {};

Level* LevelManager::m_CurrentLevel = nullptr;

void LevelManager::Initialize()
{
}

void LevelManager::Update()
{
	m_CurrentLevel->Update();
}

void LevelManager::LateUpdate()
{
	m_CurrentLevel->LateUpdate();
}

void LevelManager::Render(HDC hdc)
{
	m_CurrentLevel->Render(hdc);
}
