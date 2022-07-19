#pragma once
#include "EmberEngine/Core/Input.h"

namespace EmberEngine
{
#if defined EMBER_PLATFORM_WINDOWS
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(uint16_t keyCode) override;
		virtual bool IsMouseButtonPressedImpl(uint8_t mouseButton) override;
		virtual float GetMouseX32Impl() override;
		virtual float GetMouseY32Impl() override;
		virtual double GetMouseX64Impl() override;
		virtual double GetMouseY64Impl() override;
		virtual Vector2 GetMousePos32Impl() override;
		virtual Vector2d GetMousePos64Impl() override;
	};
#endif
}