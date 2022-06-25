#include "EmberEnginePCH.h"
#include "Matrix4x4.h"

namespace EmberEngine
{
	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top)
	{
		Matrix4x4 ortho;
		ortho.x0 = 2.0f / (right - left);
		ortho.y1 = 2.0f / (top - bottom);
		ortho.z2 = -1.0f;
		ortho.w3 = 1.0f;
		ortho.w0 = -(right + left) / (right - left);
		ortho.w1 = -(top + bottom) / (top - bottom);
		return ortho;
	}
}