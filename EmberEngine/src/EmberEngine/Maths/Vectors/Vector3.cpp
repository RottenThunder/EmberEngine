#include "EmberEnginePCH.h"
#include "Vector3.h"

namespace EmberEngine
{
	Vector3f V3Normalise(Vector3f vec)
	{
		Vector3f result = vec;
		MathF::Vector3Normalise(&result.x);
		return result;
	}

	Vector3d V3Normalise(Vector3d vec)
	{
		Vector3d result = vec;
		MathF::Vector3Normalise(&result.x);
		return result;
	}
}