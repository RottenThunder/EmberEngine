#pragma once
#include "EmberEnginePCH.h"
#include "Base.h"
#include "EmberEngine/Events/Event.h"
#include "EmberEngine/Maths/Vectors/Vector2.h"
#include "EmberEngine/Renderer/GraphicsContext.h"

namespace EmberEngine
{
	struct WindowProperties
	{
		std::string Title;
		int32_t Width;
		int32_t Height;

		WindowProperties(const std::string& title, int32_t width, int32_t height)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual int32_t GetWidth() const = 0;
		virtual int32_t GetHeight() const = 0;
		virtual int32_t GetPosX() const = 0;
		virtual int32_t GetPosY() const = 0;
		virtual Vector2i GetPos() const = 0;
		virtual GraphicsContext* GetGraphicsContext() const = 0;
		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void SetVSync(bool vSync) = 0;
		virtual bool IsVSync() const = 0;

		virtual void OnUpdate() = 0;

		static Window* Create(const WindowProperties& props);
	};
}