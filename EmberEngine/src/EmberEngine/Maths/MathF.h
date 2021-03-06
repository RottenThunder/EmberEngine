#pragma once

#define MATHF_PI 3.141592741f

namespace EmberEngine
{
	void MathFInit();
	float ToRadians(float degrees);
	float ToDegrees(float radians);

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
		virtual void Vector2MulImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector2MulImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector2MulImpl(int* dst, int* vec, int scalar) = 0;
		virtual void Vector2DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector2DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector2DivImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector2DivImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector2DivImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector2DivImpl(int* dst, int* vec, int scalar) = 0;
		virtual float Vector2MagnitudeImpl(float* vec) = 0;
		virtual float Vector2SqMagnitudeImpl(float* vec) = 0;
		virtual double Vector2MagnitudeImpl(double* vec) = 0;
		virtual double Vector2SqMagnitudeImpl(double* vec) = 0;
		virtual float Vector2MagnitudeImpl(int* vec) = 0;
		virtual float Vector2SqMagnitudeImpl(int* vec) = 0;
		virtual void Vector2NormaliseImpl(float* vec) = 0;
		virtual void Vector2NormaliseImpl(double* vec) = 0;

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
		virtual void Vector3MulImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector3MulImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector3MulImpl(int* dst, int* vec, int scalar) = 0;
		virtual void Vector3DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector3DivImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector3DivImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector3DivImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector3DivImpl(int* dst, int* vec, int scalar) = 0;
		virtual float Vector3MagnitudeImpl(float* vec) = 0;
		virtual float Vector3SqMagnitudeImpl(float* vec) = 0;
		virtual double Vector3MagnitudeImpl(double* vec) = 0;
		virtual double Vector3SqMagnitudeImpl(double* vec) = 0;
		virtual float Vector3MagnitudeImpl(int* vec) = 0;
		virtual float Vector3SqMagnitudeImpl(int* vec) = 0;
		virtual void Vector3NormaliseImpl(float* vec) = 0;
		virtual void Vector3NormaliseImpl(double* vec) = 0;
		virtual float Vector3DotImpl(float* vec1, float* vec2) = 0;
		virtual double Vector3DotImpl(double* vec1, double* vec2) = 0;
		virtual void Vector3CrossImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector3CrossImpl(double* dst, double* vec1, double* vec2) = 0;

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
		virtual void Vector4MulImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector4MulImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector4MulImpl(int* dst, int* vec, int scalar) = 0;
		virtual void Vector4DivImpl(float* dst, float* vec1, float* vec2) = 0;
		virtual void Vector4DivImpl(double* dst, double* vec1, double* vec2) = 0;
		virtual void Vector4DivImpl(int* dst, int* vec1, int* vec2) = 0;
		virtual void Vector4DivImpl(float* dst, float* vec, float scalar) = 0;
		virtual void Vector4DivImpl(double* dst, double* vec, double scalar) = 0;
		virtual void Vector4DivImpl(int* dst, int* vec, int scalar) = 0;
		virtual float Vector4MagnitudeImpl(float* vec) = 0;
		virtual float Vector4SqMagnitudeImpl(float* vec) = 0;
		virtual double Vector4MagnitudeImpl(double* vec) = 0;
		virtual double Vector4SqMagnitudeImpl(double* vec) = 0;
		virtual float Vector4MagnitudeImpl(int* vec) = 0;
		virtual float Vector4SqMagnitudeImpl(int* vec) = 0;
		virtual void Vector4NormaliseImpl(float* vec) = 0;
		virtual void Vector4NormaliseImpl(double* vec) = 0;

		//Matrix4x4 Implementation
		virtual void ResetMatrix4x4Impl(float* matrix) = 0;
		virtual void SetToIdentityImpl(float* matrix) = 0;
		virtual void MultiplyMatrix4x4Impl(float* dst, float* matrix1, float* matrix2) = 0;
		virtual void SetToTranslationImpl(float* matrix, float* vec2) = 0;
		virtual void SetToScaleImpl(float* matrix, float* vec2) = 0;
		virtual void SetToRotationImpl(float* matrix, float radians) = 0;
		virtual void SetToTranslationWithoutResetImpl(float* matrix, float* vec2) = 0;
		virtual void SetToScaleWithoutResetImpl(float* matrix, float* vec2) = 0;
		virtual void SetToRotationWithoutResetImpl(float* matrix, float radians) = 0;
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
		inline static void Vector2Mul(float* dst, float* vec, float scalar) { Instance->Vector2MulImpl(dst, vec, scalar); }
		inline static void Vector2Mul(double* dst, double* vec, double scalar) { Instance->Vector2MulImpl(dst, vec, scalar); }
		inline static void Vector2Mul(int* dst, int* vec, int scalar) { Instance->Vector2MulImpl(dst, vec, scalar); }
		inline static void Vector2Div(float* dst, float* vec1, float* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }
		inline static void Vector2Div(double* dst, double* vec1, double* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }
		inline static void Vector2Div(int* dst, int* vec1, int* vec2) { Instance->Vector2DivImpl(dst, vec1, vec2); }
		inline static void Vector2Div(float* dst, float* vec, float scalar) { Instance->Vector2DivImpl(dst, vec, scalar); }
		inline static void Vector2Div(double* dst, double* vec, double scalar) { Instance->Vector2DivImpl(dst, vec, scalar); }
		inline static void Vector2Div(int* dst, int* vec, int scalar) { Instance->Vector2DivImpl(dst, vec, scalar); }
		inline static float Vector2Magnitude(float* vec) { return Instance->Vector2MagnitudeImpl(vec); }
		inline static float Vector2SqMagnitude(float* vec) { return Instance->Vector2SqMagnitudeImpl(vec); }
		inline static double Vector2Magnitude(double* vec) { return Instance->Vector2MagnitudeImpl(vec); }
		inline static double Vector2SqMagnitude(double* vec) { return Instance->Vector2SqMagnitudeImpl(vec); }
		inline static float Vector2Magnitude(int* vec) { return Instance->Vector2MagnitudeImpl(vec); }
		inline static float Vector2SqMagnitude(int* vec) { return Instance->Vector2SqMagnitudeImpl(vec); }
		inline static void Vector2Normalise(float* vec) { Instance->Vector2NormaliseImpl(vec); }
		inline static void Vector2Normalise(double* vec) { Instance->Vector2NormaliseImpl(vec); }

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
		inline static void Vector3Mul(float* dst, float* vec, float scalar) { Instance->Vector3MulImpl(dst, vec, scalar); }
		inline static void Vector3Mul(double* dst, double* vec, double scalar) { Instance->Vector3MulImpl(dst, vec, scalar); }
		inline static void Vector3Mul(int* dst, int* vec, int scalar) { Instance->Vector3MulImpl(dst, vec, scalar); }
		inline static void Vector3Div(float* dst, float* vec1, float* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }
		inline static void Vector3Div(double* dst, double* vec1, double* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }
		inline static void Vector3Div(int* dst, int* vec1, int* vec2) { Instance->Vector3DivImpl(dst, vec1, vec2); }
		inline static void Vector3Div(float* dst, float* vec, float scalar) { Instance->Vector3DivImpl(dst, vec, scalar); }
		inline static void Vector3Div(double* dst, double* vec, double scalar) { Instance->Vector3DivImpl(dst, vec, scalar); }
		inline static void Vector3Div(int* dst, int* vec, int scalar) { Instance->Vector3DivImpl(dst, vec, scalar); }
		inline static float Vector3Magnitude(float* vec) { return Instance->Vector3MagnitudeImpl(vec); }
		inline static float Vector3SqMagnitude(float* vec) { return Instance->Vector3SqMagnitudeImpl(vec); }
		inline static double Vector3Magnitude(double* vec) { return Instance->Vector3MagnitudeImpl(vec); }
		inline static double Vector3SqMagnitude(double* vec) { return Instance->Vector3SqMagnitudeImpl(vec); }
		inline static float Vector3Magnitude(int* vec) { return Instance->Vector3MagnitudeImpl(vec); }
		inline static float Vector3SqMagnitude(int* vec) { return Instance->Vector3SqMagnitudeImpl(vec); }
		inline static void Vector3Normalise(float* vec) { Instance->Vector3NormaliseImpl(vec); }
		inline static void Vector3Normalise(double* vec) { Instance->Vector3NormaliseImpl(vec); }
		inline static float Vector3Dot(float* vec1, float* vec2) { return Instance->Vector3DotImpl(vec1, vec2); }
		inline static double Vector3Dot(double* vec1, double* vec2) { return Instance->Vector3DotImpl(vec1, vec2); }
		inline static void Vector3Cross(float* dst, float* vec1, float* vec2) { Instance->Vector3CrossImpl(dst, vec1, vec2); }
		inline static void Vector3Cross(double* dst, double* vec1, double* vec2) { Instance->Vector3CrossImpl(dst, vec1, vec2); }

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
		inline static void Vector4Mul(float* dst, float* vec, float scalar) { Instance->Vector4MulImpl(dst, vec, scalar); }
		inline static void Vector4Mul(double* dst, double* vec, double scalar) { Instance->Vector4MulImpl(dst, vec, scalar); }
		inline static void Vector4Mul(int* dst, int* vec, int scalar) { Instance->Vector4MulImpl(dst, vec, scalar); }
		inline static void Vector4Div(float* dst, float* vec1, float* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
		inline static void Vector4Div(double* dst, double* vec1, double* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
		inline static void Vector4Div(int* dst, int* vec1, int* vec2) { Instance->Vector4DivImpl(dst, vec1, vec2); }
		inline static void Vector4Div(float* dst, float* vec, float scalar) { Instance->Vector4DivImpl(dst, vec, scalar); }
		inline static void Vector4Div(double* dst, double* vec, double scalar) { Instance->Vector4DivImpl(dst, vec, scalar); }
		inline static void Vector4Div(int* dst, int* vec, int scalar) { Instance->Vector4DivImpl(dst, vec, scalar); }
		inline static float Vector4Magnitude(float* vec) { return Instance->Vector4MagnitudeImpl(vec); }
		inline static float Vector4SqMagnitude(float* vec) { return Instance->Vector4SqMagnitudeImpl(vec); }
		inline static double Vector4Magnitude(double* vec) { return Instance->Vector4MagnitudeImpl(vec); }
		inline static double Vector4SqMagnitude(double* vec) { return Instance->Vector4SqMagnitudeImpl(vec); }
		inline static float Vector4Magnitude(int* vec) { return Instance->Vector4MagnitudeImpl(vec); }
		inline static float Vector4SqMagnitude(int* vec) { return Instance->Vector4SqMagnitudeImpl(vec); }
		inline static void Vector4Normalise(float* vec) { Instance->Vector4NormaliseImpl(vec); }
		inline static void Vector4Normalise(double* vec) { Instance->Vector4NormaliseImpl(vec); }

		//Matrix4x4 Functions
		inline static void ResetMatrix4x4(float* matrix) { Instance->ResetMatrix4x4Impl(matrix); }
		inline static void SetToIdentity(float* matrix) { Instance->SetToIdentityImpl(matrix); }
		inline static void MultiplyMatrix4x4(float* dst, float* matrix1, float* matrix2) { Instance->MultiplyMatrix4x4Impl(dst, matrix1, matrix2); }
		inline static void SetToTranslation(float* matrix, float* vec2) { Instance->SetToTranslationImpl(matrix, vec2); }
		inline static void SetToScale(float* matrix, float* vec2) { Instance->SetToScaleImpl(matrix, vec2); }
		inline static void SetToRotation(float* matrix, float radians) { Instance->SetToRotationImpl(matrix, radians); }
		inline static void SetToTranslationWithoutReset(float* matrix, float* vec2) { Instance->SetToTranslationWithoutResetImpl(matrix, vec2); }
		inline static void SetToScaleWithoutReset(float* matrix, float* vec2) { Instance->SetToScaleWithoutResetImpl(matrix, vec2); }
		inline static void SetToRotationWithoutReset(float* matrix, float radians) { Instance->SetToRotationWithoutResetImpl(matrix, radians); }
	};
}