#include "TDApplication.h"

namespace TD
{
	Application::Application()
		: m_Hwnd(nullptr)
		, m_Hdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		m_Hwnd = hwnd;
		m_Hdc = GetDC(hwnd);

		//m_Player.SetPosition(0.f, 0.f);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		// ������ Ű�� �Է� -> x�� �÷���
		// ���� Ű�� �Է� -> x�� ���̳ʽ�

		//float x = m_Player.GetPositionX();
		//float y = m_Player.GetPositionY();
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01;
		//}
		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01;
		//}
		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01;
		//}
		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01;
		//}
		//// Ű���� �Է����� �ٲ� �÷��̾��� ��ġ ����
		//m_Player.SetPosition(x, y);
		// ���� �ڵ�� GameObject�� Update()�Լ��� �ִ� ���� �ٶ����� �� ����.

		m_Player.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		m_Player.Render(m_Hdc);
	}
}