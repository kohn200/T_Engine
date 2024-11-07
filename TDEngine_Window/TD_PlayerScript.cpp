#include "TD_PlayerScript.h"
#include "TD_Input.h"
#include "TD_Time.h"
#include "TD_Transform.h"
#include "TD_GameObject.h"

PlayerScript::PlayerScript()
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::Initialize()
{

}

void PlayerScript::Update()
{
	if (Input::GetKey(eKeyCode::Right))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x += 100.f * Time::GetDeltaTime();
		tr->SetPos(pos);
	}

	if (Input::GetKey(eKeyCode::Left))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x -= 100.f * Time::GetDeltaTime();
		tr->SetPos(pos);
	}
}

void PlayerScript::LateUpdate()
{
	ScriptComponent::LateUpdate();
}

void PlayerScript::Render(HDC hdc)
{
}
