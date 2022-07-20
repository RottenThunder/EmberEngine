#pragma once
#include "EmberEngine/Core/Base.h"
#include "EmberEngine/Maths/Vectors/Vector2.h"
#include "EmberEngine/Maths/Matrices/Matrix4x4.h"

namespace EmberEngine
{
	class OrthographicCamera
	{
	private:
		Matrix4x4 ProjectionMatrix;
		Matrix4x4 ViewMatrix;
		Matrix4x4 ViewProjectionMatrix;
		Vector2 Position = { 0.0f, 0.0f };
		float Rotation = 0.0f;

		void RecalculateViewMatrix();
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetPosition(const Vector2& position) { Position = position; RecalculateViewMatrix(); }
		void SetRotation(float rotation) { Rotation = rotation; RecalculateViewMatrix(); }
		void SetPositionAndRotation(const Vector2& position, float rotation) { Position = position; Rotation = rotation; RecalculateViewMatrix(); }

		const Vector2& GetPosition() const { return Position; }
		float GetRotation() const { return Rotation; }

		const Matrix4x4& GetProjectionMatrix() const { return ProjectionMatrix; }
		const Matrix4x4& GetViewMatrix() const { return ViewMatrix; }
		const Matrix4x4& GetViewProjectionMatrix() const { return ViewProjectionMatrix; }
	};
}