#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Colour
	{
	public:
		float Red, Green, Blue, Alpha;

		void SetToTransparent();
	};
}