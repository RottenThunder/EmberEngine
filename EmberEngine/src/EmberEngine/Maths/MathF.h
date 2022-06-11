#pragma once

namespace EmberEngine
{
	class MathF
	{
	protected:
		//Vector2 Implementation
		virtual void ResetVector2Impl(float* vec) = 0;
		virtual void ResetVector2Impl(double* vec) = 0;
		virtual void ResetVector2Impl(int* vec) = 0;

		//Vector3 Implementation
		virtual void ResetVector3Impl(float* vec) = 0;
		virtual void ResetVector3Impl(double* vec) = 0;
		virtual void ResetVector3Impl(int* vec) = 0;

		//Vector4 Implementation
		virtual void ResetVector4Impl(float* vec) = 0;
		virtual void ResetVector4Impl(double* vec) = 0;
		virtual void ResetVector4Impl(int* vec) = 0;
	public:
		static MathF* Instance;

		//Vector2 Functions 
		inline static void ResetVector2(float* vec) { Instance->ResetVector2Impl(vec); }
		inline static void ResetVector2(double* vec) { Instance->ResetVector2Impl(vec); }
		inline static void ResetVector2(int* vec) { Instance->ResetVector2Impl(vec); }

		//Vector3 Functions
		inline static void ResetVector3(float* vec) { Instance->ResetVector3Impl(vec); }
		inline static void ResetVector3(double* vec) { Instance->ResetVector3Impl(vec); }
		inline static void ResetVector3(int* vec) { Instance->ResetVector3Impl(vec); }

		//Vector4 Functions
		inline static void ResetVector4(float* vec) { Instance->ResetVector4Impl(vec); }
		inline static void ResetVector4(double* vec) { Instance->ResetVector4Impl(vec); }
		inline static void ResetVector4(int* vec) { Instance->ResetVector4Impl(vec); }
	};
}