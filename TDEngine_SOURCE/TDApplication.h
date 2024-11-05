#pragma once
#include "CommonInclude.h"

namespace TD
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_Hwnd;
		HDC m_Hdc;

		float m_Speed;
		float m_X;
		float m_Y;
	};
}

