#include "TD_PlayLevel.h"
#include "TD_GameObject.h"
#include "TD_Player.h"
#include "TD_Transform.h"
#include "TD_SpriteRenderer.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Initialize()
{
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(750, 200));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\C++\\T_Engine\\Resources\\PurplePotion.png");

		AddGameObject(bg);
	}
}

void PlayLevel::Update()
{
	Level::Update();
}

void PlayLevel::LateUpdate()
{
	Level::LateUpdate();
}

void PlayLevel::Render(HDC hdc)
{
	Level::Render(hdc);
}
