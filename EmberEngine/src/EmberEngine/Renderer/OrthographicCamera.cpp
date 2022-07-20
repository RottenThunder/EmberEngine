#include "EmberEnginePCH.h"
#include "OrthographicCamera.h"

namespace EmberEngine
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: ProjectionMatrix(CreateOrthographic(left, right, bottom, top)), ViewMatrix(CreateView()), ViewProjectionMatrix(ProjectionMatrix* ViewMatrix)
	{

	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		ViewMatrix = CreateView({ Position.x, Position.y, 1.0f }, { Position.x, Position.y, 0.0f }, { 0.0f, 1.0f, 0.0f }) * CreateRotation(ToRadians(-Rotation));
		ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;
	}
}