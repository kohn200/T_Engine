#include "TD_Level.h"
#include "TD_GameObject.h"

Level::Level()
	: m_Layers{}
{
	createLayer();
}

Level::~Level()
{
}

void Level::Initialize()
{
	for (auto GameLayer : m_Layers)
	{
		if (GameLayer == nullptr)
			continue;

		GameLayer->Initialize();
	}
}

void Level::Update()
{
	// 일반적인 for문
	//for (size_t i = 0; i < m_GameObjects.size(); i++)
	//{
	//	m_GameObjects[i]->Update();
	//}

	// 범위기반 for문
	for (auto GameLayer : m_Layers)
	{
		if (GameLayer == nullptr)
			continue;

		GameLayer->Update();
	}
}

void Level::LateUpdate()
{
	for (auto GameLayer : m_Layers)
	{
		if (GameLayer == nullptr)
			continue;

		GameLayer->LateUpdate();
	}
}

void Level::Render(HDC hdc)
{
	for (auto GameLayer : m_Layers)
	{
		if (GameLayer == nullptr)
			continue;

		GameLayer->Render(hdc);
	}
}

void Level::AddGameObject(GameObject* gameObject, const eLayerType type)
{
	m_Layers[(UINT)type]->AddGameObject(gameObject);
}

void Level::OnEnter()
{

}
void Level::OnExit()
{

}

void Level::createLayer()
{
	m_Layers.resize((UINT)eLayerType::Max);

	std::for_each(m_Layers.begin(), m_Layers.end(),
		[](Layer*& layer){	// 포인터 참조 *&
			layer = new Layer();
		});

	//for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
	//{
	//	m_Layers[i] = new Layer();
	//}
}
