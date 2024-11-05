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
	for (size_t i = 0; i < (UINT)eKeyCode::End; i++)	// enum class를 int형으로 형변환 (UINT)enumClass 이름
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::None;
		key.keyCode = (eKeyCode)i;

		m_Keys.push_back(key);	// 키 정보를 벡터에 저장
	}
}

void Input::Update()
{
	for (size_t i = 0; i < m_Keys.size(); i++)
	{
		// 키가 눌리거나 누르고 있는 상태
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
		else	// 키가 안눌린 상태
		{
			// 이전 프레임에 키가 눌려져 있는 상태라면
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