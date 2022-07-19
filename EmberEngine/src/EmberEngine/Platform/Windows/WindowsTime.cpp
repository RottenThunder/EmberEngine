#include "EmberEnginePCH.h"
#include "WindowsTime.h"

namespace EmberEngine
{
#if defined EMBER_PLATFORM_WINDOWS
	Time* Time::Instance = new WindowsTime();

	void WindowsTime::InitImpl()
	{
		deltaTime = 0.0;
		LastFrameTime = 0.0;

		LARGE_INTEGER dummy;
		QueryPerformanceFrequency(&dummy);
		Frequency = (double)dummy.QuadPart;
	}

	void WindowsTime::MeasureImpl()
	{
		LARGE_INTEGER dummy;
		QueryPerformanceCounter(&dummy);
		double time = (double)dummy.QuadPart;
		deltaTime = (time - LastFrameTime) / Frequency;
		LastFrameTime = time;
	}

	float WindowsTime::GetDeltaTime32Impl()
	{
		return (float)deltaTime;
	}

	double WindowsTime::GetDeltaTime64Impl()
	{
		return deltaTime;
	}
#endif
}