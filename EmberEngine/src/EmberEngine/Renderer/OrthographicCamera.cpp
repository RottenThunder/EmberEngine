#include "EmberEnginePCH.h"
#include "OrthographicCamera.h"

namespace EmberEngine
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: ProjectionMatrix(CreateOrthographic(left, right, bottom, top)), ViewMatrix(CreateView()), ViewProjectionMatrix(ProjectionMatrix* ViewMatrix)
	{

	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		ProjectionMatrix = CreateOrthographic(left, right, bottom, top);
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	}

	void OrthographicCamera::SetPosition(const Vector2& position)
	{
		Position = position;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		Rotation = rotation;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::SetPositionAndRotation(const Vector2& position, float rotation)
	{
		Position = position;
		Rotation = rotation;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::SetPositionAndRotationAndProjection(float left, float right, float bottom, float top, const Vector2& position, float rotation)
	{
		ProjectionMatrix = CreateOrthographic(left, right, bottom, top);
		Position = position;
		Rotation = rotation;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		ViewMatrix = CreateView({ Position.x, Position.y, 1.0f }, { Position.x, Position.y, 0.0f }, { 0.0f, 1.0f, 0.0f }) * CreateRotation(ToRadians(-Rotation));
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	}
}