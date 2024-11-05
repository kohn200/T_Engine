#include "TDInput.h"

vector<Input::Key> Input::m_Keys= {};

int ASCII[(int)eKeyCode::End] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
};

void Input::Initialize()
{
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)	// enum class�� int������ ����ȯ (UINT)enumClass �̸�
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		m_Keys.push_back(key);	// Ű ������ ���Ϳ� ����
	}
}

void Input::Update()
{
	for (size_t i = 0; i < m_Keys.size(); i++)
	{
		// Ű�� �����ų� ������ �ִ� ����
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			if (m_Keys[i].bPressed == true)
			{
				m_Keys[i].state = eKeyState::Pressed;
			}
			else
			{
				m_Keys[i].state = eKeyState::Down;
			}

			m_Keys[i].bPressed = true;
		}
		else	// Ű�� �ȴ��� ����
		{
			// ���� �����ӿ� Ű�� ������ �ִ� ���¶��
			if (m_Keys[i].bPressed == true)
			{
				m_Keys[i].state = eKeyState::Up;
			}
			else
			{
				m_Keys[i].state = eKeyState::None;
			}

			m_Keys[i].bPressed = false;
		}
	}
}