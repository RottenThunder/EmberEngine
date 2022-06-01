#pragma once
#include "EmberEnginePCH.h"
#include "Event.h"

namespace EmberEngine
{
	class KeyEvent : public Event
	{
	protected:
		uint16_t KeyCode;

		KeyEvent(uint16_t keyCode)
			: KeyCode(keyCode) {}

	public:
		inline uint16_t GetKeyCode() const { return KeyCode; }

		virtual uint8_t GetCategoryFlags() const override { return EventCategory::Keyboard | EventCategory::Input; }
	};

	class KeyPressedEvent : public KeyEvent
	{
	private:
		uint64_t RepeatCount;
	public:
		KeyPressedEvent(uint16_t keyCode, uint64_t repeatCount)
			: KeyEvent(keyCode), RepeatCount(repeatCount) {}

		inline uint64_t GetRepeatCount() const { return RepeatCount; }

		virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::KeyPressed; }
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint16_t keyCode)
			: KeyEvent(keyCode) {}

		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		virtual std::string GetName() const override
		{
			std::stringstream ss;
			ss << "[EMBER]: KeyReleasedEvent: " << KeyCode;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::KeyPressed; }
	};
}