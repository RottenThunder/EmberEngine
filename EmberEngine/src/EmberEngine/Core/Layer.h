#pragma once
#include "Base.h"
#include "EmberEngine/Events/ApplicationEvent.h"
#include "EmberEngine/Events/KeyEvent.h"
#include "EmberEngine/Events/MouseEvent.h"

namespace EmberEngine
{
	class Layer
	{
	protected:
		std::string Name;
	public:
		Layer(const std::string& name);
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return Name; }
	};
}