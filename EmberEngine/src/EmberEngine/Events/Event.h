#pragma once
#include "EmberEnginePCH.h"
#include "EmberEngine/Core/Base.h"

namespace EmberEngine
{
	enum class EventType : uint8_t
	{
		None = 0,
		WindowClose, WindowResize, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum class EventCategory : uint8_t
	{
		None = 0,
		Application = BIT_FIELD(0),
		Input = BIT_FIELD(1),
		Keyboard = BIT_FIELD(2),
		Mouse = BIT_FIELD(3),
		MouseButton = BIT_FIELD(4)
	};

	class Event
	{
	private:
		friend class EventDispatcher;
	public:
		bool handled = false;
		virtual EventType GetEventType() const = 0;
		virtual uint8_t GetCategoryFlags() const = 0;
		virtual std::string GetName() const = 0;

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & static_cast<uint8_t>(category);
		}
	};

	class EventDispatcher
	{
	private:
		Event& event;
	public:
		EventDispatcher(Event& e)
			: event(e) {}

		template<typename T>
		bool Dispatch(std::function<bool(T&)> func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.handled = func(*(T*)&event);
				return true;
			}

			return false;
		}
	};
}