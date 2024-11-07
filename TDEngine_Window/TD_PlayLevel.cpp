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

	// ���� ������Ʈ ��������� ���ҽ��� ���� Load�صд�.

	bg = Instantiate<Player>(eLayerType::BackGround, Vector2(100.f, 100.f));

	SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
	sr->SetTexture(Assets::Find<Texture>(L"BG"));

	//bg->AddComponent<ScriptComponent>();	�������� ScriptComponent�� ���� PlayerScript::Update()�� ������ �ʾҴ�����..
	bg->AddComponent<PlayerScript>();

	// ���� ������Ʈ ������ ���̾�� ���ӿ�����Ʈ���� init()�Լ� ȣ��
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

	// �÷��̾ ���� ���� ������ ���� �ʿ� ����� �÷��̾��� ��ǥ�� 0���� �ʱ�ȭ
	//Transform* tr = bg->GetComponent<Transform>();
	//tr->SetPos(Vector2(0, 0));
}
