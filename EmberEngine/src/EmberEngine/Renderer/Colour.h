#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Colour
	{
	public:
		float Red, Green, Blue, Alpha;
	public:
		Colour();
		Colour(float red, float green, float blue, float alpha);

		void SetToTransparent();
	};
}