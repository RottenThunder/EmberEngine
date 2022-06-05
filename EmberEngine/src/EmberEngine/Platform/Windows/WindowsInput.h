#pragma once
#include "EmberEngine/Core/Input.h"

namespace EmberEngine
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(uint16_t keyCode) override;
		virtual bool IsMouseButtonPressedImpl(uint8_t mouseButton) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}