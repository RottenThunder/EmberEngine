#pragma once

namespace EmberEngine
{
	class Time
	{
	private:
		static Time* Instance;
	protected:
		double deltaTime;
		double LastFrameTime;

		virtual void InitImpl() = 0;
		virtual void MeasureImpl() = 0;
		virtual float GetDeltaTime32Impl() = 0;
		virtual double GetDeltaTime64Impl() = 0;
	public:
		inline static void Init() { Instance->InitImpl(); }
		inline static void Measure() { Instance->MeasureImpl(); }
		inline static float GetDeltaTime32() { return Instance->GetDeltaTime32Impl(); }
		inline static double GetDeltaTime64() { return Instance->GetDeltaTime64Impl(); }
	};
}