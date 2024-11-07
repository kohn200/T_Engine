#pragma once
#include "..\\TDEngine_SOURCE\\TD_Assets.h"
#include "..\\TDEngine_SOURCE\\TD_Texture.h"



namespace TD
{
	void LoadAssets()
	{
		Assets::Load<Texture>(L"BG", L"D:\\C++\\T_Engine\\Resources\\PurplePotion.png");
	}
}
