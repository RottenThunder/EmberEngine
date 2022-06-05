#pragma once
#include <stdint.h>
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
		//TODO: Need to add a function to get the Mouse Position as a Vector2
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	public:
		inline static bool IsKeyPressed(uint16_t keyCode) { return Instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(uint8_t mouseButton) { return Instance->IsMouseButtonPressedImpl(mouseButton); }
		inline static float GetMouseX() { return Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return Instance->GetMouseYImpl(); }
	};
}