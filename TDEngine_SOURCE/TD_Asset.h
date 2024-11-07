#pragma once
#include "TD_Entity.h"

class Asset abstract : public Entity		// ���� ���� �Լ��� �ϳ��� �����Ѵٸ� or abstractŰ���尡 �ִٸ� �߻� Ŭ������ �Ѵ�. 
{
public:
	Asset() = delete;			// �⺻ ������ ���� ����
	Asset(eAssetType type);
	 virtual ~Asset();

	 virtual HRESULT Load(const wstring& path) = 0;	// ���� �����Լ��� ���� �޸𸮿� �Ҵ��� �Ұ���������. ��� ���� Ŭ������ ���

	 const wstring& GetPath() { return m_Path; }
	 void SetPath(const wstring& path) { m_Path = path; }	// wstring path�� �Ű������� �ް� �Ǹ� �����ؼ� �Ѱ��ְ� �Ǿ
															// ��� ���� 20�� �̻��� �Ǹ� �ϳ��ϳ� �ݺ����� �����鼭 �����Ͽ� �Ѱ��ְ� �ȴ�.
															// ������ ���� �޾Ƽ� �Ѱ��ְ� �Ǹ� ������ �״�� �Ѿ�� �ǹǷ�
															// ������ ũ�⸦ ������ ũ�� ������ ����ϰ� �ȴ�.


private:
	wstring m_Path;		// ���
	const eAssetType m_Type;

};

// ���ӿ��� ���Ǵ� �����͵��� ����
// �̹���, ����, ���� �÷��̵����� ����