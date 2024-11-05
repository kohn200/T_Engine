#include "TD_Time.h"

LARGE_INTEGER Time::s_CpuFrequency = {};
LARGE_INTEGER Time::s_PrevFrequency = {};
LARGE_INTEGER Time::s_CurrentFrequency = {};
float Time::s_DeltaTime = 0.f;

void Time::Initialize()
{
	// CPU ���� ������
	QueryPerformanceFrequency(&s_CpuFrequency);

	// ���α׷��� ���� ���� �� ���� ������
	QueryPerformanceCounter(&s_PrevFrequency);
}

void Time::Update()
{
	QueryPerformanceCounter(&s_CurrentFrequency);

	float differenceFrequency = static_cast<float>(s_CurrentFrequency.QuadPart - s_PrevFrequency.QuadPart);

	s_DeltaTime = differenceFrequency / static_cast<float>(s_CpuFrequency.QuadPart);
	s_PrevFrequency.QuadPart = s_CurrentFrequency.QuadPart;
}

void Time::Render(HDC hdc)
{
	static float time = 0.f;

	// ��� �ð�
	time += s_DeltaTime;
	wchar_t TimeStr[50] = L"";
	swprintf_s(TimeStr, 50, L"Time: %f", time);
	int Timelen = wcsnlen_s(TimeStr, 50);
	TextOut(hdc, 0, 0, TimeStr, Timelen);

	// FPS
	float fps = 1.0f / s_DeltaTime;
	wchar_t FpsStr[50] = L"";
	swprintf_s(FpsStr, 50, L"FPS: %d", (int)fps);
	int Fpslen = wcsnlen_s(FpsStr, 50);
	TextOut(hdc, 0, 20, FpsStr, Fpslen);

}
