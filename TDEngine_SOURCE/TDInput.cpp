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
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)	// enum class�� int������ ����ȯ (UINT)enumClass �̸�
	{
		Key key = {};
		key.bPressed = false;
		key.keyState = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		m_Keys.push_back(key);	// Ű ������ ���Ϳ� ����
	}
}

void Input::updateKeys()
{
	// � Ű�� ���ȴ��� �˻�
	for_each(m_Keys.begin(), m_Keys.end(),
		[](Key& key) -> void
		{
			updateKey(key);
		});
}

void Input::updateKey(Key& key)
{
	if (isKeyDown(key.keyCode))	// Ű�� ���ȴ��� ����
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
	// Ű�� ���� ��Ȳ

	if (key.bPressed == true)	// ���� �����Ӻ��� �����־��ٸ�
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
	// Ű�� �� ��Ȳ

	if (key.bPressed == true)	// ���� �����ӿ� Ű�� �����־��ٸ�
	{
		key.keyState = eKeyState::Up;
	}
	else
	{
		key.keyState = eKeyState::None;
	}

	key.bPressed = false;
}
