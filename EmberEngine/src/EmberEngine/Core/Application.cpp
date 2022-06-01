#include "EmberEnginePCH.h"
#include "Application.h"
#include "EmberEngine/Events/ApplicationEvent.h"
#include "EmberEngine/Events/KeyEvent.h"
#include "EmberEngine/Events/MouseEvent.h"

namespace EmberEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowMovedEvent e0(1280, 720);
		std::cout << e0.GetX() << std::endl;
		std::cout << e0.GetY() << std::endl;
		std::cout << e0.IsInCategory(EventCategory::Application) << std::endl;
		std::cout << e0.GetName() << std::endl;

		WindowResizeEvent e1(1280, 720);
		std::cout << e1.GetWidth() << std::endl;
		std::cout << e1.GetHeight() << std::endl;
		std::cout << e1.IsInCategory(EventCategory::Mouse) << std::endl;
		std::cout << e1.GetName() << std::endl;

		KeyPressedEvent e2(10, 2);
		std::cout << e2.GetKeyCode() << std::endl;
		std::cout << e2.GetRepeatCount() << std::endl;
		std::cout << e2.IsInCategory(EventCategory::MouseButton) << std::endl;
		std::cout << e2.GetName() << std::endl;

		KeyReleasedEvent e3(10);
		std::cout << e3.GetKeyCode() << std::endl;
		std::cout << e3.IsInCategory(EventCategory::Input) << std::endl;
		std::cout << e3.GetName() << std::endl;

		MouseButtonPressedEvent e4(2);
		std::cout << (uint16_t)e4.GetMouseButton() << std::endl;
		std::cout << e4.IsInCategory(EventCategory::Keyboard) << std::endl;
		std::cout << e4.GetName() << std::endl;

		MouseButtonReleasedEvent e5(2);
		std::cout << (uint16_t)e5.GetMouseButton() << std::endl;
		std::cout << e5.IsInCategory(EventCategory::MouseButton) << std::endl;
		std::cout << e5.GetName() << std::endl;

		MouseMovedEvent e6(480.0f, 379.0f);
		std::cout << e6.GetX() << std::endl;
		std::cout << e6.GetY() << std::endl;
		std::cout << e6.IsInCategory(EventCategory::Application) << std::endl;
		std::cout << e6.GetName() << std::endl;

		MouseScrolledEvent e7(245.0f, 569.0f);
		std::cout << e7.GetXOffset() << std::endl;
		std::cout << e7.GetYOffset() << std::endl;
		std::cout << e7.IsInCategory(EventCategory::None) << std::endl;
		std::cout << e7.GetName() << std::endl;

		WindowCloseEvent c;
		std::cout << c.IsInCategory(EventCategory::Input) << std::endl;
		std::cout << c.GetName() << std::endl;

		while (true);
	}
}