#include "TD_LevelManager.h"

map<wstring, Level*> LevelManager::m_Levels = {};

Level* LevelManager::m_CurrentLevel = nullptr;

Level* LevelManager::LoadLevel(const wstring& name)
{
	if (m_CurrentLevel != nullptr)
		m_CurrentLevel->OnExit();	// 현재 레벨에서 나갈때 마다 기존에 있던 것들 해제

	// 현재 레벨을 로드
	map<wstring, Level*>::iterator iter = m_Levels.find(name);

	// 현재 찾고자 하는 레벨이 맵에 없다면 nullptr 반환
	if (iter == m_Levels.end())
		return nullptr;

	// 있다면 현재 레벨에 저장
	m_CurrentLevel = iter->second;
	m_CurrentLevel->OnEnter();

	return iter->second;
}

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
