#pragma once
#include "TD_Asset.h"

class Assets
{
public:
	template <typename T>	// Asset의 종류가 Texture, Sound 등 많기 때문에 template를 사용
	static T* Find(const wstring& key)
	{
		map<wstring, Asset*>::iterator iter = m_Assets.find(key);
		
		if (iter == m_Assets.end())
			return nullptr;

		//m_Asset = iter->second;

		return dynamic_cast<T*>(iter->second);
	}

	template <typename T>
	static T* Load(const wstring& key, const wstring& path)
	{
		T* asset = Assets::Find<T>(key);

		if (asset != nullptr)
			return asset;

		asset = new T();
		if (FAILED(asset->Load(path)))
		{
			//MessageBox(nullptr, L"Image Load Failed.", L"Error", MB_OK);
			assert(false);
			return nullptr;
		}

		asset->SetName(key);
		asset->SetPath(path);

		m_Assets.insert(make_pair(key, asset));

		return asset;
	}

private:
	static map<wstring, Asset*> m_Assets;
	//static Asset* m_Asset;
};



