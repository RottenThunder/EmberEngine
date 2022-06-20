#include "EmberEnginePCH.h"
#include "Vector4.h"

namespace EmberEngine
{
	Vector4f V4Normalise(Vector4f vec)
	{
		Vector4f result = vec;
		MathF::Vector4Normalise(&result.x);
		return result;
	}

	Vector4d V4Normalise(Vector4d vec)
	{
		Vector4d result = vec;
		MathF::Vector4Normalise(&result.x);
		return result;
	}
}