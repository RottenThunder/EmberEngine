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
			uint16_t Width;
			uint16_t Height;
			uint16_t XPosition;
			uint16_t YPosition;
			std::function<void(Event&)> EventCallback;
			bool VSync;
		};

		GLFWwindow* WindowObject;
		WindowData windowData;

		virtual void Init(const WindowProperties& props);
		virtual void Terminate();
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual inline uint16_t GetWidth() const override { return windowData.Width; }
		virtual inline uint16_t GetHeight() const override { return windowData.Height; }
		virtual inline uint16_t GetPosX() const override { return windowData.XPosition; }
		virtual inline uint16_t GetPosY() const override { return windowData.YPosition; }
		virtual inline void* GetNativeWindow() const override { return WindowObject; }

		virtual inline void SetEventCallback(const std::function<void(Event&)>& callback) override { windowData.EventCallback = callback; }
		virtual void SetVSync(bool vSync) override;
		virtual bool IsVSync() const override;

		virtual void OnUpdate() override;
	};
}