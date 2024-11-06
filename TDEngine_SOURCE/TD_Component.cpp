#include "TD_Component.h"
#include "TD_GameObject.h"

Component::Component()
	: m_Owner(nullptr)
{
}

Component::~Component()
{
}

void Component::Initialize()
{
}

void Component::Update()
{
}

void Component::LateUpdate()
{
}

void Component::Render(HDC hdc)
{
}
