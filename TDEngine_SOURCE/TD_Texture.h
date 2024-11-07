#pragma once
#include "TD_Asset.h"

enum class eTextureType
{
	Bmp,
	Png,
	None,
};

class Texture : public Asset
{
public:


	Texture();
	~Texture();

	virtual HRESULT Load(const wstring& path) override;

	UINT GetWidth() { return m_Width; }
	UINT GetHeight() { return m_Height; }
	HDC GetHdc() { return m_Hdc; }
	eTextureType GetTextureType() { return m_TextureType; }
	Gdiplus::Image* GetImage() { return m_Image; }

private:
	Gdiplus::Image* m_Image;	// .png 파일 그릴때 사용 png는 32bit
	HBITMAP m_Bitmap;			// bmp는 24bit
	HDC m_Hdc;
	eTextureType m_TextureType;

	UINT m_Width;
	UINT m_Height;
};

