#pragma once
#include "CommonInclude.h"

enum class eKeyState	// 키 이벤트
{
	Down,
	Pressed,
	Up,
	None,
};

enum class eKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M, 
	Left, Right, Down, Up,
	SpaceBar,
	End
};

class Input
{
public:
	struct Key
	{
		eKeyCode keyCode;
		eKeyState keyState;
		bool bPressed;
	};

	static void Initialize();
	static void Update();

	static bool GetKeyDown(eKeyCode keyCode) { return s_Keys[(UINT)keyCode].keyState == eKeyState::Down; }
	static bool GetKeyUp(eKeyCode keyCode) { return s_Keys[(UINT)keyCode].keyState == eKeyState::Up; }
	static bool GetKey(eKeyCode keyCode) { return s_Keys[(UINT)keyCode].keyState == eKeyState::Pressed; }

private:
	// 다른 클래스에서 호출될 함수가 아니면 private 영역에 넣기
	static void createKeys();
	static void updateKeys();
	static void updateKey(Key& key);
	static bool isKeyDown(eKeyCode keyCode);
	static void updateKeyDown(Key& key);
	static void updateKeyUp(Key& key);


private:
	static vector<Key> s_Keys;
	
};

