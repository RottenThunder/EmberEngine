#pragma once
#include "EmberEnginePCH.h"
#include "Event.h"
#include "EmberEngine/Maths/Vectors/Vector2.h"

namespace EmberEngine
{
	class WindowMovedEvent : public Event
	{
	private:
		Vector2i Pos;
	public:
		WindowMovedEvent(Vector2i pos)
			: Pos(pos) {}

		inline int32_t GetX() const { return Pos.x; }
		inline int32_t GetY() const { return Pos.y; }
		inline Vector2i GetPos() const { return Pos; }

		virtual EventType GetEventType() const override { return EventType::WindowMoved; }
		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::Application); }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: WindowMovedEvent: " << Pos.x << ", " << Pos.y;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowMoved; }
	};

	class WindowResizeEvent : public Event
	{
	private:
		int32_t Width, Height;
	public:
		WindowResizeEvent(int32_t width, int32_t height)
			: Width(width), Height(height) {}

		inline int32_t GetWidth() const { return Width; }
		inline int32_t GetHeight() const { return Height; }

		virtual EventType GetEventType() const override { return EventType::WindowResize; }
		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::Application); }
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
		virtual uint8_t GetCategoryFlags() const override { return static_cast<uint8_t>(EventCategory::Application); }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: WindowCloseEvent";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowClose; }
	};
}