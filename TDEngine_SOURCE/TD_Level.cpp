#include "TD_Level.h"
#include "TD_GameObject.h"

Level::Level()
	: m_GameObjects{}
{
}

Level::~Level()
{
}

void Level::Initialize()
{
}

void Level::Update()
{
	// �Ϲ����� for��
	//for (size_t i = 0; i < m_GameObjects.size(); i++)
	//{
	//	m_GameObjects[i]->Update();
	//}

	// ������� for��
	for (auto GameObject : m_GameObjects)
	{
		GameObject->Update();
	}
}

void Level::LateUpdate()
{
	for (auto GameObject : m_GameObjects)
	{
		GameObject->LateUpdate();
	}
}

void Level::Render(HDC hdc)
{
	for (auto GameObject : m_GameObjects)
	{
		GameObject->Render(hdc);
	}
}

void Level::AddGameObject(GameObject* gameObject)
{
	m_GameObjects.push_back(gameObject);
	// Level�� m_GameObject�� protected�� �Ͽ� �ڽ� Ŭ������ ����� �� �ְ� ���� �ʰ�
	// �ڽ� Ŭ�������� AddGameObject()�Լ��� �ҷ��� ����� ������

	// m_GameObject�� ��, �浹, ���� ������鿡�� ���ǰ� �ֱ� ������
	// private�� �����Ϳ� ���� ���� ���ϰ� ���� ���α׷��� ��ĥ ������� �������Բ� �Ͽ���,
	// AddGameObject()�Լ��� ���ؼ��� m_GameObject�� �����Ͽ� ����ó���� �Ͽ� �������� Ȯ���ϱ� �����̴�.
}
