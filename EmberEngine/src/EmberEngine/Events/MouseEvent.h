#pragma once
#include "EmberEnginePCH.h"
#include "Event.h"

namespace EmberEngine
{
	class MouseMovedEvent : public Event
	{
	private:
		float MouseX, MouseY;
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: MouseX(mouseX), MouseY(mouseY) {}

		inline float GetX() const { return MouseX; }
		inline float GetY() const { return MouseY; }

		virtual EventType GetEventType() const override { return EventType::MouseMoved; }
		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::Mouse) | static_cast<uint8_t>(EventCategory::Input); }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: MouseMovedEvent: " << MouseX << ", " << MouseY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMoved; }
	};

	class MouseScrolledEvent : public Event
	{
	private:
		float XOffset, YOffset;
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: XOffset(xOffset), YOffset(yOffset) {}

		inline float GetXOffset() const { return XOffset; }
		inline float GetYOffset() const { return YOffset; }

		virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::Mouse) | static_cast<uint8_t>(EventCategory::Input); }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: MouseScrolledEvent: " << XOffset << ", " << YOffset;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScrolled; }
	};

	class MouseButtonEvent : public Event
	{
	protected:
		int32_t Button;

		MouseButtonEvent(int32_t button)
			: Button(button) {}
	public:
		inline int32_t GetMouseButton() const { return Button; }

		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::MouseButton) | static_cast<uint8_t>(EventCategory::Input); }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int32_t button)
			: MouseButtonEvent(button) {}

		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: MouseButtonPressedEvent: " << (uint16_t)Button;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MouseButtonPressed; }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int32_t button)
			: MouseButtonEvent(button) {}

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: MouseButtonReleasedEvent: " << (uint16_t)Button;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MouseButtonReleased; }
	};
}