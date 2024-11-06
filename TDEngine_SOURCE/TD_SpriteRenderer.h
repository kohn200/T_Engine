#pragma once
#include "TD_Entity.h"
#include "TD_Component.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	void ImageLoad(const wstring& path);

private:
	Gdiplus::Image* m_Image;
	UINT m_Width;
	UINT m_Height;
};
