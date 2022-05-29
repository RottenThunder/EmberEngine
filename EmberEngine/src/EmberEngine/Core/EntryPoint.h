#pragma once
#include "Application.h"

extern EmberEngine::Application* EmberEngine::CreateApplication();

int main()
{
	auto app = EmberEngine::CreateApplication();
	app->Run();
	delete app;
}