#include "TDInput.h"

vector<Input::Key> Input::m_Keys= {};

int ASCII[(int)eKeyCode::End] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
};

void Input::Initialize()
{
	createKeys();
}

void Input::Update()
{
	updateKeys();
}

void Input::createKeys()
{
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)	// enum class를 int형으로 형변환 (UINT)enumClass 이름
	{
		Key key = {};
		key.bPressed = false;
		key.keyState = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		m_Keys.push_back(key);	// 키 정보를 벡터에 저장
	}
}

void Input::updateKeys()
{
	// 어떤 키가 눌렸는지 검사
	for_each(m_Keys.begin(), m_Keys.end(),
		[](Key& key) -> void
		{
			updateKey(key);
		});
}

void Input::updateKey(Key& key)
{
	if (isKeyDown(key.keyCode))	// 키가 눌렸는지 여부
	{
		updateKeyDown(key);
	}
	else
	{
		updateKeyUp(key);
	}
}

bool Input::isKeyDown(eKeyCode keyCode)
{
	return GetAsyncKeyState(ASCII[(UINT)keyCode]) & 0x8000;
}

void Input::updateKeyDown(Key& key)
{
	// 키를 누른 상황

	if (key.bPressed == true)	// 이전 프레임부터 눌려있었다면
	{
		key.keyState = eKeyState::Pressed;
	}
	else
	{
		key.keyState = eKeyState::Down;
	}

	key.bPressed = true;
}

void Input::updateKeyUp(Key& key)
{
	// 키를 땐 상황

	if (key.bPressed == true)	// 이전 프레임에 키가 눌려있었다면
	{
		key.keyState = eKeyState::Up;
	}
	else
	{
		key.keyState = eKeyState::None;
	}

	key.bPressed = false;
}
