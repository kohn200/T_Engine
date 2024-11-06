#include "TD_PlayLevel.h"
#include "TD_GameObject.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Initialize()
{
	GameObject* obj = new GameObject();
	AddGameObject(obj);
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
