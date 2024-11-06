#pragma once
#include "CommonInclude.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetName(const wstring& name) { m_Name = name; }
	wstring& GetName() { return m_Name; }

private:
	wstring m_Name;
};

