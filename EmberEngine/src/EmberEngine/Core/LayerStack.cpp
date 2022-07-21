#include "EmberEnginePCH.h"
#include "LayerStack.h"

namespace EmberEngine
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		Layers.emplace_back(layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(Layers.begin(), Layers.end(), layer);
		if (it != Layers.end())
			Layers.erase(it);
	}
}