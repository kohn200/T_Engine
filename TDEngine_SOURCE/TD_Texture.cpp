#include "TD_Texture.h"
#include "TD_GameInstance.h"

// �ش� ���������� �������� �˸��� Ű���� extern
extern GameInstance gInstance;	// main���� ������ ���������� �ش� Ŭ�������� ����ϱ� ����
								// main���� ������ �̸��� ���ƾ� �Ѵ�!!

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

	wstring ext = path.substr(path.find_first_of(L".") + 1);	// Ȯ���� ��� ���¹� 

	if (ext == L"bmp")		// bmp �϶�
	{
		m_TextureType = eTextureType::Bmp;
		m_Bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (m_Bitmap == nullptr)
			return S_FALSE;

		BITMAP info = {};
		GetObject(m_Bitmap, sizeof(BITMAP), &info);

		m_Width = info.bmWidth;
		m_Height = info.bmHeight;

		HDC mainDC = gInstance.GetHDC();	// ���� DC ������
		m_Hdc = CreateCompatibleDC(mainDC);	// ���ο� DC ����

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);		// ���� ���� DC�� Bitmap�� �����ִ� �۾�
		DeleteObject(oldBitmap);

	}
	else if (ext == L"png")		// png �϶�
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
