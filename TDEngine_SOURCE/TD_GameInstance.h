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

	// ���� ������Ʈ�� �þ ���� Play1,2,3,4, ... �̷������� �߰��� ����� �ϴµ� 
	// �̷��� ���� vector�� player�� ������Ʈ���� ���� �ϰԲ� ����
	//GameObject m_Player;

	//vector<GameObject*> m_GameObjects;	
	
	// ���� �ν��Ͻ��� ������Ʈ���� ��� �ִ°� �ƴ϶�
	// ���� �ν��Ͻ��� �� Level(Scene)�� ��� �ְ�,
	// �� Level(Scene)���� ������Ʈ���� ��� �ְԲ� �Ѵ�.

	//vector<Level*> m_Levels;
};


