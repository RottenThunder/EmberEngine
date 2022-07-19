#pragma once
#include "EmberEngine/Core/Time.h"

namespace EmberEngine
{
#if defined EMBER_PLATFORM_WINDOWS
	class WindowsTime : public Time
	{
	protected:
		double Frequency;

		virtual void InitImpl() override;
		virtual void MeasureImpl() override;
		virtual float GetDeltaTime32Impl() override;
		virtual double GetDeltaTime64Impl() override;
	};
#endif
}