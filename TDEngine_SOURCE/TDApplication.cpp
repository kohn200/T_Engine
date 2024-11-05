#include "TDApplication.h"

namespace TD
{
	Application::Application()
		: m_Hwnd(nullptr)
		, m_Hdc(nullptr)
		, m_Speed(0.0f)
		, m_X(0.0f)
		, m_Y(0.0f)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		m_Hwnd = hwnd;
		m_Hdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		m_Speed += 0.1f;

		// 오른쪽 키를 입력 -> x가 플러스
		// 왼쪽 키를 입력 -> x가 마이너스

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_X -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_X += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_Y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_Y += 0.01f;
		}
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));		 
		HBRUSH OldBrush = (HBRUSH)SelectObject(m_Hdc, BlueBrush);    

		HPEN RedPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		HPEN OldPen = (HPEN)SelectObject(m_Hdc, RedPen);
		SelectObject(m_Hdc, OldPen);

		Rectangle(m_Hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

		SelectObject(m_Hdc, OldBrush);		
		DeleteObject(BlueBrush);			
		DeleteObject(RedPen);
	}
}