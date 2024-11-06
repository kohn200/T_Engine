#pragma once
#include "CommonInclude.h"
#include "TD_GameObject.h"


class GameInstance
{
public:
	GameInstance();
	~GameInstance();

	void Initialize(HWND hwnd, UINT width, UINT height);
	void Run();

	void Update();
	void LateUpdate();
	void Render();

private:
	HWND m_Hwnd;
	HDC m_Hdc;
	
	HDC m_BackHdc;
	HBITMAP m_BackBuffer;

	UINT m_Width;
	UINT m_Height;

	GameObject m_Player;
};


