#include "TD_Texture.h"
#include "TD_GameInstance.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern GameInstance gInstance;	// main에서 선언한 전역변수를 해당 클래스에서 사용하기 위함
								// main에서 선언한 이름과 같아야 한다!!

Texture::Texture()
	: Asset(eAssetType::Texture)
	, m_Image(nullptr)
	, m_Bitmap(nullptr)
	, m_Hdc(nullptr)
	, m_TextureType(eTextureType::None)
	, m_Width(0)
	, m_Height(0)
{

}

Texture::~Texture()
{
}

HRESULT Texture::Load(const wstring& path)
{

	wstring ext = path.substr(path.find_first_of(L".") + 1);	// 확장자 들고 오는법 

	if (ext == L"bmp")		// bmp 일때
	{
		m_TextureType = eTextureType::Bmp;
		m_Bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (m_Bitmap == nullptr)
			return S_FALSE;

		BITMAP info = {};
		GetObject(m_Bitmap, sizeof(BITMAP), &info);

		m_Width = info.bmWidth;
		m_Height = info.bmHeight;

		HDC mainDC = gInstance.GetHDC();	// 메인 DC 가져옴
		m_Hdc = CreateCompatibleDC(mainDC);	// 새로운 DC 만듬

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);		// 새로 만든 DC와 Bitmap을 엮어주는 작업
		DeleteObject(oldBitmap);

	}
	else if (ext == L"png")		// png 일때
	{
		m_TextureType = eTextureType::Png;
		m_Image = Gdiplus::Image::FromFile(path.c_str());

		if (m_Image == nullptr)
			return S_FALSE;

		m_Width = m_Image->GetWidth();
		m_Height = m_Image->GetHeight();
	}
	

	return S_OK;
}
