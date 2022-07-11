#pragma once
#include "EmberEngine/Maths/Vectors/Vector2.h"
#include "Base.h"

namespace EmberEngine
{
	class Input
	{
	private:
		static Input* Instance;
	protected:
		virtual bool IsKeyPressedImpl(uint16_t keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(uint8_t mouseButton) = 0;
		virtual float GetMouseX32Impl() = 0;
		virtual float GetMouseY32Impl() = 0;
		virtual double GetMouseX64Impl() = 0;
		virtual double GetMouseY64Impl() = 0;
		virtual Vector2 GetMousePos32Impl() = 0;
		virtual Vector2d GetMousePos64Impl() = 0;
	public:
		inline static bool IsKeyPressed(uint16_t keyCode) { return Instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(uint8_t mouseButton) { return Instance->IsMouseButtonPressedImpl(mouseButton); }
		inline static float GetMouseX32() { return Instance->GetMouseX32Impl(); }
		inline static float GetMouseY32() { return Instance->GetMouseY32Impl(); }
		inline static double GetMouseX64() { return Instance->GetMouseX64Impl(); }
		inline static double GetMouseY64() { return Instance->GetMouseY64Impl(); }
		inline static Vector2 GetMousePos32() { return Instance->GetMousePos32Impl(); }
		inline static Vector2d GetMousePos64() { return Instance->GetMousePos64Impl(); }
	};
}