#pragma once
#include "CommonInclude.h"

class Level;

class LevelManager
{
public:
	template <typename T>
	static Level* CreateLevel(const wstring& name)
	{
		T* level = new T();
		level->SetName(name);
		level->Initialize();

		m_Levels.insert(std::make_pair(name, level));
		
		return level;
	};

	static Level* LoadLevel(const wstring& name)
	{
		// ���� ������ �ε�
		map<wstring, Level*>::iterator iter = m_Levels.find(name);

		// ���� ã���� �ϴ� ������ �ʿ� ���ٸ� nullptr ��ȯ
		if (iter == m_Levels.end())
			return nullptr;

		// �ִٸ� ���� ������ ����
		m_CurrentLevel = iter->second;

		return iter->second;
	}

	static void Initialize();	// �ϳ��ϳ��� ������ ���鶧 ���
	static void Update();		// �ش� �� ������Ʈ
	static void	LateUpdate();
	static void Render(HDC hdc);		// �ش� �� ����

private:
	// ���� �Ŵ������� ��� ������ ��� ���� �ϰԲ� ���Ϳ� �ְ� ���
	//static vector<Level*> m_Levels;
	static map<wstring, Level*> m_Levels;
	
	// ���� �÷����ϴ� ������ �ϳ��̱⿡ ���� ������ ��� ��Ű�� ���� ���� ������ ����
	static Level* m_CurrentLevel;

	// static���� ������ ����ȭ ��Ű�� ������ cpp���� �ʱ�ȭ �۾��� ����� �Ѵ�!!!!!!!
};

