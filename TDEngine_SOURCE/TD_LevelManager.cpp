#include "TD_LevelManager.h"

map<wstring, Level*> LevelManager::m_Levels = {};

Level* LevelManager::m_CurrentLevel = nullptr;

Level* LevelManager::LoadLevel(const wstring& name)
{
	if (m_CurrentLevel != nullptr)
		m_CurrentLevel->OnExit();	// ���� �������� ������ ���� ������ �ִ� �͵� ����

	// ���� ������ �ε�
	map<wstring, Level*>::iterator iter = m_Levels.find(name);

	// ���� ã���� �ϴ� ������ �ʿ� ���ٸ� nullptr ��ȯ
	if (iter == m_Levels.end())
		return nullptr;

	// �ִٸ� ���� ������ ����
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
