#pragma once
#include "CommonInclude.h"
#include "TD_GameObject.h"


class GameInstance
{
public:
	GameInstance();
	~GameInstance();

	void Initialize(HWND hwnd);
	void Run();

	void Update();
	void LateUpdate();

	void Render();

private:
	HWND m_Hwnd;
	HDC m_Hdc;

	GameObject m_Player;
};


