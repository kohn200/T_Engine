#pragma once

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
	Texture,		// 이미지
	// Actor,
	// Shader,
	Sound,			// 사운드
	SaveGame,		// 데이터 저장
	End,
};
