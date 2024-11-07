#pragma once
#include "CommonInclude.h"
#include "TD_Level.h"


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
		if(m_CurrentLevel != nullptr)
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

	static void Initialize();	// 하나하나의 레벨을 만들때 사용
	static void Update();		// 해당 씬 업데이트
	static void	LateUpdate();
	static void Render(HDC hdc);		// 해당 씬 렌더

private:
	// 레벨 매니저에서 모든 레벨을 들고 관리 하게끔 벡터에 넣고 사용
	//static vector<Level*> m_Levels;
	static map<wstring, Level*> m_Levels;
	
	// 현재 플레이하는 레벨은 하나이기에 현재 레벨을 재생 시키기 위한 레벨 포인터 변수
	static Level* m_CurrentLevel;

	// static으로 변수를 전역화 시키면 무조건 cpp에서 초기화 작업을 해줘야 한다!!!!!!!
};

