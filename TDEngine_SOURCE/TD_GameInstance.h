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

	HDC GetHDC() { return m_Hdc; }

private:
	void clearRenderTarget();
	void copyRenderTarget(HDC source, HDC dest);
	void adjustWindowRect(HWND hwnd, UINT width, UINT height);
	void createBuffer(UINT width, UINT height);
	void initializeEtc();

private:
	HWND m_Hwnd;
	HDC m_Hdc;
	
	HDC m_BackHdc;
	HBITMAP m_BackBuffer;

	UINT m_Width;
	UINT m_Height;

	// 게임 오브젝트가 늘어날 수록 Play1,2,3,4, ... 이런식으로 추가를 해줘야 하는데 
	// 이렇게 말고 vector로 player나 오브젝트들을 관리 하게끔 수정
	//GameObject m_Player;

	//vector<GameObject*> m_GameObjects;	
	
	// 게임 인스턴스가 오브젝트들을 들고 있는게 아니라
	// 게임 인스턴스는 각 Level(Scene)을 들고 있고,
	// 각 Level(Scene)에서 오브젝트들을 들고 있게끔 한다.

	//vector<Level*> m_Levels;
};


