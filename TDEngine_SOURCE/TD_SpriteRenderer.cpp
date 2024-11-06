#include "TD_SpriteRenderer.h"
#include "TD_GameObject.h"
#include "TD_Transform.h"

SpriteRenderer::SpriteRenderer()
	: m_Image(nullptr)
	, m_Width(0)
	, m_Height(0)
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
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(m_Image, Gdiplus::Rect(pos.x, pos.y, m_Width, m_Height));
}

void SpriteRenderer::ImageLoad(const wstring& path)
{
	m_Image = Gdiplus::Image::FromFile(path.c_str());
	m_Width = m_Image->GetWidth();
	m_Height = m_Image->GetHeight();
}
