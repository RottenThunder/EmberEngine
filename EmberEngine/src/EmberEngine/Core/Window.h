#pragma once
#include "EmberEnginePCH.h"
#include "Base.h"
#include "EmberEngine/Events/Event.h"
#include "EmberEngine/Renderer/GraphicsContext.h"

namespace EmberEngine
{
	struct WindowProperties
	{
		std::string Title;
		uint16_t Width;
		uint16_t Height;

		WindowProperties(const std::string& title, uint16_t width, uint16_t height)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual uint16_t GetWidth() const = 0;
		virtual uint16_t GetHeight() const = 0;
		virtual uint16_t GetPosX() const = 0;
		virtual uint16_t GetPosY() const = 0;
		virtual GraphicsContext* GetGraphicsContext() const = 0;
		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void SetVSync(bool vSync) = 0;
		virtual bool IsVSync() const = 0;

		virtual void OnUpdate() = 0;

		static Window* Create(const WindowProperties& props);
	};
}