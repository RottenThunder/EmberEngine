#pragma once
#include "Application.h"
#include "ProcessorAnalyser.h"
#include "EmberEngine/Maths/MathF.h"

extern EmberEngine::Application* EmberEngine::CreateApplication();

int main()
{
	EmberEngine::ProcessorAnalyser::Analyse();
	EmberEngine::MathFInit();
	EmberEngine::Time::Init();

	auto app = EmberEngine::CreateApplication();
	app->Run();
	delete app;
}