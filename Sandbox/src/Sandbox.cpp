#include <EmberEngine.h>

class ExampleLayer : public EmberEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		//std::cout << "ExampleLayer is Updating" << std::endl;
	}

	void OnEvent(EmberEngine::Event& e) override
	{
		std::cout << e.GetName() << std::endl;
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