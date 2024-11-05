#pragma once
#include "CommonInclude.h"
#include "TDGameObject.h"

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

		GameObject m_Player;
	};
}

