#pragma once
#include "CommonInclude.h"

enum class eKeyState
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
	End
};

class Input
{
public:
	struct Key
	{
		eKeyCode keyCode;
		eKeyState state;
		bool bPressed;
	};

	static void Initialize();
	static void Update();
	
	static bool GetKeyDown(eKeyCode keyCode) { return m_Keys[(UINT)keyCode].state == eKeyState::Down; }
	static bool GetKeyUp(eKeyCode keyCode) { return m_Keys[(UINT)keyCode].state == eKeyState::Up; }
	static bool GetKey(eKeyCode keyCode) { return m_Keys[(UINT)keyCode].state == eKeyState::Pressed; }

private:
	static vector<Key> m_Keys;
	
};

