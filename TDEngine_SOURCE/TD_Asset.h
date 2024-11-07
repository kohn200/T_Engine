#pragma once
#include "TD_Entity.h"

class Asset abstract : public Entity		// 순수 가상 함수가 하나라도 존재한다면 or abstract키워드가 있다면 추상 클래스라 한다. 
{
public:
	Asset() = delete;			// 기본 생성자 막아 놓기
	Asset(eAssetType type);
	 virtual ~Asset();

	 virtual HRESULT Load(const wstring& path) = 0;	// 순수 가상함수로 실제 메모리에 할당이 불가능해진다. 상속 받은 클래스가 사용

	 const wstring& GetPath() { return m_Path; }
	 void SetPath(const wstring& path) { m_Path = path; }	// wstring path로 매개변수를 받게 되면 복사해서 넘겨주게 되어서
															// 경로 값이 20자 이상이 되면 하나하나 반복문을 돌리면서 복사하여 넘겨주게 된다.
															// 하지만 참조 받아서 넘겨주게 되면 원본이 그대로 넘어가게 되므로
															// 데이터 크기를 포인터 크기 정도만 사용하게 된다.


private:
	wstring m_Path;		// 경로
	const eAssetType m_Type;

};

// 게임에서 사용되는 데이터들의 종류
// 이미지, 사운드, 게임 플레이데이터 저장