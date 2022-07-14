#pragma once
#include "EmberEngine/Core/Window.h"
#include <GLFW/glfw3.h>

namespace EmberEngine
{
	class WindowsWindow : public Window
	{
	private:
		struct WindowData
		{
			std::string Title;
			int32_t Width;
			int32_t Height;
			Vector2i Position;
			std::function<void(Event&)> EventCallback;
			bool VSync;
		};

		GraphicsContext* Context;
		GLFWwindow* WindowObject;
		WindowData windowData;

		virtual void Init(const WindowProperties& props);
		virtual void Terminate();
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual inline int32_t GetWidth() const override { return windowData.Width; }
		virtual inline int32_t GetHeight() const override { return windowData.Height; }
		virtual inline int32_t GetPosX() const override { return windowData.Position.x; }
		virtual inline int32_t GetPosY() const override { return windowData.Position.y; }
		virtual inline Vector2i GetPos() const override { return windowData.Position; }
		virtual inline GraphicsContext* GetGraphicsContext() const override { return Context; }
		virtual inline void* GetNativeWindow() const override { return WindowObject; }

		virtual inline void SetEventCallback(const std::function<void(Event&)>& callback) override { windowData.EventCallback = callback; }
		virtual void SetVSync(bool vSync) override;
		virtual bool IsVSync() const override;

		virtual void OnUpdate() override;
	};
}