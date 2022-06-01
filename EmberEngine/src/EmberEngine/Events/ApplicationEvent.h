#pragma once
#include "EmberEnginePCH.h"
#include "Event.h"

namespace EmberEngine
{
	class WindowMovedEvent : public Event
	{
	private:
		uint16_t PosX, PosY;
	public:
		WindowMovedEvent(uint16_t x, uint16_t y)
			: PosX(x), PosY(y) {}

		inline uint16_t GetX() const { return PosX; }
		inline uint16_t GetY() const { return PosY; }

		virtual EventType GetEventType() const override { return EventType::WindowMoved; }
		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Application; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: WindowMovedEvent: " << PosX << ", " << PosY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowMoved; }
	};

	class WindowResizeEvent : public Event
	{
	private:
		uint16_t Width, Height;
	public:
		WindowResizeEvent(uint16_t width, uint16_t height)
			: Width(width), Height(height) {}

		inline uint16_t GetWidth() const { return Width; }
		inline uint16_t GetHeight() const { return Height; }

		virtual EventType GetEventType() const override { return EventType::WindowResize; }
		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Application; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: WindowResizeEvent: " << Width << ", " << Height;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowResize; }
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		virtual EventType GetEventType() const override { return EventType::WindowClose; }
		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Application; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: WindowCloseEvent";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowClose; }
	};
}