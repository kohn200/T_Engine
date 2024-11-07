#include "TD_SpriteRenderer.h"
#include "TD_GameObject.h"
#include "TD_Transform.h"


SpriteRenderer::SpriteRenderer()
	: Component(eComponentType::SpriteRenderer)
	, m_Texture(nullptr)
	, m_Scale(Vector2::One)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Initialize()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(HDC hdc)
{
	if (m_Texture == nullptr)
		return;

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (m_Texture->GetTextureType() == eTextureType::Bmp)
	{
		TransparentBlt(hdc, pos.x, pos.y, m_Texture->GetWidth(), m_Texture->GetHeight(), m_Texture->GetHdc(),
			0, 0, m_Texture->GetWidth(), m_Texture->GetHeight(), RGB(255,0,255));
	}
	else if (m_Texture->GetTextureType() == eTextureType::Png)
	{
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(m_Texture->GetImage(), Gdiplus::Rect(pos.x, pos.y, m_Texture->GetWidth(), m_Texture->GetHeight()));
	}
}

