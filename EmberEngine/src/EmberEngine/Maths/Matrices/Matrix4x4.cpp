#include "EmberEnginePCH.h"
#include "Matrix4x4.h"

namespace EmberEngine
{
	Matrix4x4 CreateTranslation(float x, float y)
	{
		Matrix4x4 translation;
		translation.x0 = 1.0f;
		translation.y1 = 1.0f;
		translation.z2 = 1.0f;
		translation.w3 = 1.0f;
		translation.w0 = x;
		translation.w1 = y;
		return translation;
	}

	Matrix4x4 CreateTranslation(float* vec2)
	{
		Matrix4x4 translation;
		translation.x0 = 1.0f;
		translation.y1 = 1.0f;
		translation.z2 = 1.0f;
		translation.w3 = 1.0f;
		translation.w0 = vec2[0];
		translation.w1 = vec2[1];
		return translation;
	}

	Matrix4x4 CreateScale(float sx, float sy)
	{
		Matrix4x4 scale;
		scale.x0 = sx;
		scale.y1 = sy;
		scale.z2 = 1.0f;
		scale.w3 = 1.0f;
		return scale;
	}

	Matrix4x4 CreateScale(float* vec2)
	{
		Matrix4x4 scale;
		scale.x0 = vec2[0];
		scale.y1 = vec2[1];
		scale.z2 = 1.0f;
		scale.w3 = 1.0f;
		return scale;
	}

	Matrix4x4 CreateRotation(float radians)
	{
		Matrix4x4 rotation;
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		rotation.w3 = 1.0f;
		rotation.z2 = 1.0f;
		rotation.x0 = cosAngle;
		rotation.x1 = sinAngle;
		rotation.y0 = -sinAngle;
		rotation.y1 = cosAngle;
		return rotation;
	}

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