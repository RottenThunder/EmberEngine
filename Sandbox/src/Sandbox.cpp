#include <EmberEngine.h>

class ExampleLayer : public EmberEngine::Layer
{
private:
	EmberEngine::Ref<EmberEngine::Texture> texture1;
	EmberEngine::Ref<EmberEngine::Texture> texture2;

	EmberEngine::OrthographicCamera orthoCamera;
	EmberEngine::Vector2 cameraPosition;
public:
	ExampleLayer() : Layer("Example"), orthoCamera(-1.6f, 1.6f, -0.9f, 0.9f), cameraPosition(0.0f, 0.0f)
	{
		texture1 = EmberEngine::Texture::Create("Assets/Textures/Checkerboard.png");
		texture2 = EmberEngine::Texture::Create("Assets/Textures/TestCharacter.png");
	}

	void OnUpdate() override
	{
		//std::cout << "DeltaTime: " << EmberEngine::Time::GetDeltaTime32() << std::endl;

		EmberEngine::Renderer::ClearScreen(0.25f, 0.25f, 0.25f);

		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_A))
		{
			cameraPosition.x -= EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_D))
		{
			cameraPosition.x += EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_W))
		{
			cameraPosition.y += EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_S))
		{
			cameraPosition.y -= EmberEngine::Time::GetDeltaTime32();
		}

		EmberEngine::Renderer::BeginScene(orthoCamera);

		EmberEngine::Renderer::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 1.0f, 0.0f, 0.0f });
		EmberEngine::Renderer::DrawQuad({ 1.0f, 1.0f }, { 1.5f, 0.5f }, { 0.0f, 1.0f, 0.0f });
		EmberEngine::Renderer::DrawQuad({ -1.0f, -1.0f }, { 2.5f, 1.5f }, { 0.0f, 0.0f, 1.0f });
		EmberEngine::Renderer::DrawQuad({ 0.5f, 0.5f }, { 2.0f, 1.0f }, texture1, { 0.5f, 0.0f, 0.0f });
		EmberEngine::Renderer::DrawQuad({ 1.5f, 0.5f }, { 1.0f, 1.0f }, texture2);

		EmberEngine::Renderer::EndScene();

		orthoCamera.SetPositionAndRotation(cameraPosition, orthoCamera.GetRotation() + EmberEngine::Time::GetDeltaTime32() * 10.0f);
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