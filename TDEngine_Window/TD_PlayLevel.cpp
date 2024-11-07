#include "TD_PlayLevel.h"
#include "TD_GameObject.h"
#include "TD_Player.h"
#include "TD_Transform.h"
#include "TD_SpriteRenderer.h"
#include "TD_Input.h"
#include "TD_TitleLevel.h"
#include "TD_LevelManager.h"
#include "TD_Object.h"
#include "TD_Assets.h"
#include "TD_Texture.h"
#include "TD_PlayerScript.h"

PlayLevel::PlayLevel()
	: bg(nullptr)
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Initialize()
{

	// 게임 오브젝트 만들기전에 리소스들 전부 Load해둔다.

	bg = Instantiate<Player>(eLayerType::BackGround, Vector2(100.f, 100.f));

	SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
	sr->SetTexture(Assets::Find<Texture>(L"BG"));

	//bg->AddComponent<ScriptComponent>();	기존에는 ScriptComponent로 만들어서 PlayerScript::Update()에 들어오지 않았던거임..
	bg->AddComponent<PlayerScript>();

	// 게임 오브젝트 생성후 레이어와 게임오브젝트들의 init()함수 호출
	Level::Initialize();

}

void PlayLevel::Update()
{
	Level::Update();
}

void PlayLevel::LateUpdate()
{
	Level::LateUpdate();

	if (Input::GetKeyDown(eKeyCode::N))
	{
		LevelManager::LoadLevel(L"TitleLevel");
	}
}

void PlayLevel::Render(HDC hdc)
{
	Level::Render(hdc);
	wchar_t str[50] = L"Play Level";
	TextOut(hdc, 750, 0, str, 10);
}

void PlayLevel::OnEnter()
{
	Level::OnEnter();
}

void PlayLevel::OnExit()
{
	Level::OnExit();

	// 플레이어가 현재 맵을 나가고 다음 맵에 입장시 플레이어의 좌표를 0으로 초기화
	//Transform* tr = bg->GetComponent<Transform>();
	//tr->SetPos(Vector2(0, 0));
}
