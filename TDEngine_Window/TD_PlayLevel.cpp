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
		Player* player = new Player();

		Transform* tr = player->AddComponent<Transform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TR");

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(player);
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
