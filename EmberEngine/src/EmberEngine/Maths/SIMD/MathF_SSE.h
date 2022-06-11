#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class MathF_SSE : public MathF
	{
	protected:
		//Vector2 Implementation
		virtual void ResetVector2Impl(float* vec) override;
		virtual void ResetVector2Impl(double* vec) override;
		virtual void ResetVector2Impl(int* vec) override;

		//Vector3 Implementation
		virtual void ResetVector3Impl(float* vec) override;
		virtual void ResetVector3Impl(double* vec) override;
		virtual void ResetVector3Impl(int* vec) override;

		//Vector4 Implementation
		virtual void ResetVector4Impl(float* vec) override;
		virtual void ResetVector4Impl(double* vec) override;
		virtual void ResetVector4Impl(int* vec) override;
	};
}