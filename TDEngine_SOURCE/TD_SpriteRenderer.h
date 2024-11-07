#pragma once
#include "TD_Entity.h"
#include "TD_Component.h"
#include "TD_Texture.h"

using namespace math;

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;	// 텍스쳐를 들고와서 그리는 곳

	void SetTexture(Texture* texture) { m_Texture = texture; }
	void SetSize(Vector2 scale) { m_Scale = scale; }
private:
	Texture* m_Texture;
	Vector2 m_Scale;
};

