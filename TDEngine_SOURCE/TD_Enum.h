#pragma once

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Script,
	End,
};

enum class eLayerType
{
	None,
	BackGround,
	// Tree
	// Character
	Player,
	Max = 16,
};

enum class eAssetType
{
	Texture,		// �̹���
	// Actor,
	// Shader,
	Sound,			// ����
	SaveGame,		// ������ ����
	End,
};
