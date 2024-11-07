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
	virtual void Render(HDC hdc) override;	// �ؽ��ĸ� ���ͼ� �׸��� ��

	void SetTexture(Texture* texture) { m_Texture = texture; }
	void SetSize(Vector2 scale) { m_Scale = scale; }
private:
	Texture* m_Texture;
	Vector2 m_Scale;
};

