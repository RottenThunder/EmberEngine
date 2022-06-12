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
		virtual void Vector2AddImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector2AddImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector2AddImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector2SubImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector2SubImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector2SubImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector2MulImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector2MulImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector2MulImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector2DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector2DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector2DivImpl(int* dst, int* vec1, int* vec2) = 0;

		//Vector3 Implementation
		virtual void ResetVector3Impl(float* vec) = 0;
		virtual void ResetVector3Impl(double* vec) = 0;
		virtual void ResetVector3Impl(int* vec) = 0;
		virtual void Vector3AddImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3AddImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector3AddImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector3SubImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3SubImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector3SubImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector3MulImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3MulImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector3MulImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector3DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector3DivImpl(int* dst, int* vec1, int* vec2) = 0;

		//Vector4 Implementation
		virtual void ResetVector4Impl(float* vec) = 0;
		virtual void ResetVector4Impl(double* vec) = 0;
		virtual void ResetVector4Impl(int* vec) = 0;
		virtual void Vector4AddImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector4AddImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector4AddImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector4SubImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector4SubImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector4SubImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector4MulImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector4MulImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector4MulImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector4DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector4DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector4DivImpl(int* dst, int* vec1, int* vec2) = 0;
	public:
		static MathF* Instance;

		//Vector2 Functions 
		inline static void ResetVector2(float* vec) { Instance->ResetVector2Impl(vec); }
		inline static void ResetVector2(double* vec) { Instance->ResetVector2Impl(vec); }
		inline static void ResetVector2(int* vec) { Instance->ResetVector2Impl(vec); }
		inline static void Vector2Add(float* dst, float* vec1, float* vec2) { Instance->Vector2AddImpl(dst, vec1, vec2); }
		inline static void Vector2Add(double* dst, double* vec1, double* vec2) { Instance->Vector2AddImpl(dst, vec1, vec2); }
		inline static void Vector2Add(int* dst, int* vec1, int* vec2) { Instance->Vector2AddImpl(dst, vec1, vec2); }
		inline static void Vector2Sub(float* dst, float* vec1, float* vec2) { Instance->Vector2SubImpl(dst, vec1, vec2); }
		inline static void Vector2Sub(double* dst, double* vec1, double* vec2) { Instance->Vector2SubImpl(dst, vec1, vec2); }
		inline static void Vector2Sub(int* dst, int* vec1, int* vec2) { Instance->Vector2SubImpl(dst, vec1, vec2); }
		inline static void Vector2Mul(float* dst, float* vec1, float* vec2) { Instance->Vector2MulImpl(dst, vec1, vec2); }
		inline static void Vector2Mul(double* dst, double* vec1, double* vec2) { Instance->Vector2MulImpl(dst, vec1, vec2); }
		inline static void Vector2Mul(int* dst, int* vec1, int* vec2) { Instance->Vector2MulImpl(dst, vec1, vec2); }
		inline static void Vector2Div(float* dst, float* vec1, float* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }
		inline static void Vector2Div(double* dst, double* vec1, double* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }
		inline static void Vector2Div(int* dst, int* vec1, int* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }

		//Vector3 Functions
		inline static void ResetVector3(float* vec) { Instance->ResetVector3Impl(vec); }
		inline static void ResetVector3(double* vec) { Instance->ResetVector3Impl(vec); }
		inline static void ResetVector3(int* vec) { Instance->ResetVector3Impl(vec); }
		inline static void Vector3Add(float* dst, float* vec1, float* vec2) { Instance->Vector3AddImpl(dst, vec1, vec2); }
		inline static void Vector3Add(double* dst, double* vec1, double* vec2) { Instance->Vector3AddImpl(dst, vec1, vec2); }
		inline static void Vector3Add(int* dst, int* vec1, int* vec2) { Instance->Vector3AddImpl(dst, vec1, vec2); }
		inline static void Vector3Sub(float* dst, float* vec1, float* vec2) { Instance->Vector3SubImpl(dst, vec1, vec2); }
		inline static void Vector3Sub(double* dst, double* vec1, double* vec2) { Instance->Vector3SubImpl(dst, vec1, vec2); }
		inline static void Vector3Sub(int* dst, int* vec1, int* vec2) { Instance->Vector3SubImpl(dst, vec1, vec2); }
		inline static void Vector3Mul(float* dst, float* vec1, float* vec2) { Instance->Vector3MulImpl(dst, vec1, vec2); }
		inline static void Vector3Mul(double* dst, double* vec1, double* vec2) { Instance->Vector3MulImpl(dst, vec1, vec2); }
		inline static void Vector3Mul(int* dst, int* vec1, int* vec2) { Instance->Vector3MulImpl(dst, vec1, vec2); }
		inline static void Vector3Div(float* dst, float* vec1, float* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }
		inline static void Vector3Div(double* dst, double* vec1, double* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }
		inline static void Vector3Div(int* dst, int* vec1, int* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }

		//Vector4 Functions
		inline static void ResetVector4(float* vec) { Instance->ResetVector4Impl(vec); }
		inline static void ResetVector4(double* vec) { Instance->ResetVector4Impl(vec); }
		inline static void ResetVector4(int* vec) { Instance->ResetVector4Impl(vec); }
		inline static void Vector4Add(float* dst, float* vec1, float* vec2) { Instance->Vector4AddImpl(dst, vec1, vec2); }
		inline static void Vector4Add(double* dst, double* vec1, double* vec2) { Instance->Vector4AddImpl(dst, vec1, vec2); }
		inline static void Vector4Add(int* dst, int* vec1, int* vec2) { Instance->Vector4AddImpl(dst, vec1, vec2); }
		inline static void Vector4Sub(float* dst, float* vec1, float* vec2) { Instance->Vector4SubImpl(dst, vec1, vec2); }
		inline static void Vector4Sub(double* dst, double* vec1, double* vec2) { Instance->Vector4SubImpl(dst, vec1, vec2); }
		inline static void Vector4Sub(int* dst, int* vec1, int* vec2) { Instance->Vector4SubImpl(dst, vec1, vec2); }
		inline static void Vector4Mul(float* dst, float* vec1, float* vec2) { Instance->Vector4MulImpl(dst, vec1, vec2); }
		inline static void Vector4Mul(double* dst, double* vec1, double* vec2) { Instance->Vector4MulImpl(dst, vec1, vec2); }
		inline static void Vector4Mul(int* dst, int* vec1, int* vec2) { Instance->Vector4MulImpl(dst, vec1, vec2); }
		inline static void Vector4Div(float* dst, float* vec1, float* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
		inline static void Vector4Div(double* dst, double* vec1, double* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
		inline static void Vector4Div(int* dst, int* vec1, int* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
	};
}