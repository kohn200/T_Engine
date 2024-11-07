#include "TD_Player.h"
#include "TD_Input.h"
#include "TD_Transform.h"
#include "TD_Time.h"

void Player::Initialize()
{
	GameObject::Initialize();
}

void Player::Update()
{
	GameObject::Update();
}

void Player::LateUpdate()
{
	GameObject::LateUpdate();

	if (Input::GetKey(eKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x += 100.f * Time::GetDeltaTime();
		tr->SetPos(pos);
	}
}

void Player::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
