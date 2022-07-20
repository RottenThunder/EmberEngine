#include "EmberEnginePCH.h"
#include "Matrix4x4.h"
#include "EmberEngine/Maths/Vectors/Vector3.h"

namespace EmberEngine
{
	Matrix4x4 CreateTranslation(float x, float y)
	{
		Matrix4x4 translation;
		translation.ToIdentity();
		translation.x3 = x;
		translation.y3 = y;
		return translation;
	}

	Matrix4x4 CreateTranslation(float* vec2)
	{
		Matrix4x4 translation;
		translation.ToIdentity();
		translation.x3 = vec2[0];
		translation.y3 = vec2[1];
		return translation;
	}

	Matrix4x4 CreateScale(float sx, float sy)
	{
		Matrix4x4 scale;
		scale.Reset();
		scale.x0 = sx;
		scale.y1 = sy;
		scale.z2 = 1.0f;
		scale.w3 = 1.0f;
		return scale;
	}

	Matrix4x4 CreateScale(float* vec2)
	{
		Matrix4x4 scale;
		scale.Reset();
		scale.x0 = vec2[0];
		scale.y1 = vec2[1];
		scale.z2 = 1.0f;
		scale.w3 = 1.0f;
		return scale;
	}

	Matrix4x4 CreateRotation(float radians)
	{
		Matrix4x4 rotation;
		rotation.Reset();
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

	Matrix4x4 CreateView()
	{
		//This Function assumes that the eye is at {0, 0, 1}
		//This Function assumes that the target is at {0, 0, 0}
		//This Function assumes that the up is at {0, 1, 0}

		//[ 1, -0,  0, -0]
		//[ 0,  1,  0, -0]
		//[-0, -0,  1, -1]
		//[ 0,  0,  0,  1]

		Matrix4x4 view;
		view.ToIdentity();
		view.z3 = -1.0f;
		return view;
	}

	Matrix4x4 CreateView(Vector3 eye, Vector3 target, Vector3 up)
	{
		Matrix4x4 view;
		Vector3 f = V3Normalise(target - eye);
		Vector3 s = V3Normalise(V3Cross(f, up));
		Vector3 u = V3Cross(s, f);
		view.x0 = s.x;
		view.x1 = s.y;
		view.x2 = s.z;
		view.y0 = u.x;
		view.y1 = u.y;
		view.y2 = u.z;
		view.z0 = -f.x;
		view.z1 = -f.y;
		view.z2 = -f.z;
		view.x3 = -V3Dot(s, eye);
		view.y3 = -V3Dot(u, eye);
		view.z3 = V3Dot(f, eye);
		view.w0 = 0.0f;
		view.w1 = 0.0f;
		view.w2 = 0.0f;
		view.w3 = 1.0f;
		return view;
	}

	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top)
	{
		Matrix4x4 ortho;
		ortho.Reset();
		ortho.x0 = 2.0f / (right - left);
		ortho.y1 = 2.0f / (top - bottom);
		ortho.z2 = -1.0f;
		ortho.w3 = 1.0f;
		ortho.x3 = -(right + left) / (right - left);
		ortho.y3 = -(top + bottom) / (top - bottom);
		return ortho;
	}
}