#include "TD_Layer.h"

Layer::Layer()
	: m_GameObjects{}
{

}

Layer::~Layer()
{

}

void Layer::Initialize()
{
	for (auto GameObject : m_GameObjects)
	{
		if (GameObject == nullptr)
			continue;

		GameObject->Initialize();
	}
}
void Layer::Update()
{
	for (auto GameObject : m_GameObjects)
	{
		if (GameObject == nullptr)
			continue;

		GameObject->Update();
	}
}
void Layer::LateUpdate()
{
	for (auto GameObject : m_GameObjects)
	{
		if (GameObject == nullptr)
			continue;

		GameObject->LateUpdate();
	}
}
void Layer::Render(HDC hdc)
{
	for (auto GameObject : m_GameObjects)
	{
		if (GameObject == nullptr)
			continue;

		GameObject->Render(hdc);
	}
}

void Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	m_GameObjects.push_back(gameObject);
	// Level의 m_GameObject를 protected로 하여 자식 클래스가 사용할 수 있게 하지 않고
	// 자식 클래스에서 AddGameObject()함수를 불러서 사용한 이유는

	// m_GameObject는 씬, 충돌, 로직 여러방면에서 사용되고 있기 때문에
	// private로 데이터에 직접 접근 못하게 막아 프로그램에 미칠 영향력이 적어지게끔 하였고,
	// AddGameObject()함수를 통해서만 m_GameObject에 접근하여 예외처리를 하여 안정성을 확보하기 위함이다.
}