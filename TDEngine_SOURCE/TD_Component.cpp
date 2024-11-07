#include "TD_Component.h"
#include "TD_GameObject.h"

Component::Component(eComponentType type)
	: m_Owner(nullptr)
	, m_ComponentType(type)
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
