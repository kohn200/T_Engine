#pragma once
#include "CommonInclude.h"

class Time
{
public:
	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	static float GetDeltaTime() { return s_DeltaTime; }

private:
	static LARGE_INTEGER s_CpuFrequency;
	static LARGE_INTEGER s_PrevFrequency;
	static LARGE_INTEGER s_CurrentFrequency;
	static float s_DeltaTime;
};

