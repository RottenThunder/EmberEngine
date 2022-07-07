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
		translation.x3 = x;
		translation.y3 = y;
		return translation;
	}

	Matrix4x4 CreateTranslation(float* vec2)
	{
		Matrix4x4 translation;
		translation.x0 = 1.0f;
		translation.y1 = 1.0f;
		translation.z2 = 1.0f;
		translation.w3 = 1.0f;
		translation.x3 = vec2[0];
		translation.y3 = vec2[1];
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
		rotation.x0 = cosAngle;
		rotation.y0 = sinAngle;
		rotation.x1 = -sinAngle;
		rotation.y1 = cosAngle;
		rotation.z2 = 1.0f;
		rotation.w3 = 1.0f;
		return rotation;
	}

	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top)
	{
		Matrix4x4 ortho;
		ortho.x0 = 2.0f / (right - left);
		ortho.y1 = 2.0f / (top - bottom);
		ortho.z2 = -1.0f;
		ortho.w3 = 1.0f;
		ortho.x3 = -(right + left) / (right - left);
		ortho.y3 = -(top + bottom) / (top - bottom);
		return ortho;
	}
}