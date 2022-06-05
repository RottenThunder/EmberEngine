#include <EmberEngine.h>

class ExampleLayer : public EmberEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_A))
		{
			std::cout << "A Key Was Pressed!" << std::endl;
		}
	}

	void OnEvent(EmberEngine::Event& e) override
	{
		if (e.GetEventType() == EmberEngine::EventType::KeyPressed)
		{
			EmberEngine::KeyPressedEvent& keyEvent = (EmberEngine::KeyPressedEvent&)e;
			std::cout << char(keyEvent.GetKeyCode()) << std::endl;
		}
	}
};

class Sandbox : public EmberEngine::Application
{
private:
	ExampleLayer* Example = nullptr;
public:
	Sandbox()
		: Example(new ExampleLayer)
	{
		PushLayer(Example);
		std::cout << "Initial Window Position: " << GetWindowPosX() << ", " << GetWindowPosY() << std::endl;
		std::cout << "Initial Window Size: " << GetWindowWidth() << ", " << GetWindowHeight() << std::endl;
	}

	~Sandbox()
	{
		PopLayer(Example);
	}
};

EmberEngine::Application* EmberEngine::CreateApplication()
{
	return new Sandbox();
}