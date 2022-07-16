#include "EmberEnginePCH.h"
#include "Colour.h"

namespace EmberEngine
{
	void Colour::SetToTransparent()
	{
		MathF::ResetVector4(&Red);
	}
}