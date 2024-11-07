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
	// Level�� m_GameObject�� protected�� �Ͽ� �ڽ� Ŭ������ ����� �� �ְ� ���� �ʰ�
	// �ڽ� Ŭ�������� AddGameObject()�Լ��� �ҷ��� ����� ������

	// m_GameObject�� ��, �浹, ���� ������鿡�� ���ǰ� �ֱ� ������
	// private�� �����Ϳ� ���� ���� ���ϰ� ���� ���α׷��� ��ĥ ������� �������Բ� �Ͽ���,
	// AddGameObject()�Լ��� ���ؼ��� m_GameObject�� �����Ͽ� ����ó���� �Ͽ� �������� Ȯ���ϱ� �����̴�.
}