#pragma once
#include "TD_Layer.h"
#include "TD_GameObject.h"
#include "TD_LevelManager.h"
#include "TD_Level.h"
#include "TD_Component.h"
#include "TD_Transform.h"


template <typename T>
static T* Instantiate(eLayerType type)
{
	T* gameObject = new T();
	Level* currentLevel = LevelManager::GetCurrentLevel();
	Layer* currentLayer = currentLevel->GetLayer(type);
	currentLayer->AddGameObject(gameObject);

	return gameObject;
}

template <typename T>
static T* Instantiate(eLayerType type, math::Vector2 position)
{
	T* gameObject = new T();
	Level* currentLevel = LevelManager::GetCurrentLevel();
	Layer* currentLayer = currentLevel->GetLayer(type);
	currentLayer->AddGameObject(gameObject);

	Transform* tr = gameObject->GetComponent<Transform>();
	tr->SetPos(position);

	return gameObject;
}