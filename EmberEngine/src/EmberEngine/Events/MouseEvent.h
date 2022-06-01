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
		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Mouse | EventCategory::Input; }
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
		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Mouse | EventCategory::Input; }
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
		uint8_t Button;

		MouseButtonEvent(uint8_t button)
			: Button(button) {}
	public:
		inline uint8_t GetMouseButton() const { return Button; }

		virtual uint8_t GetCategoryFlags() const override { return EventCategory::MouseButton | EventCategory::Input; }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(uint8_t button)
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
		MouseButtonReleasedEvent(uint8_t button)
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