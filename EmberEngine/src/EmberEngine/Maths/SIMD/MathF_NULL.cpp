#include "EmberEnginePCH.h"
#include "MathF_NULL.h"

namespace EmberEngine
{
	//Vector2 Implementation

	void MathF_NULL::ResetVector2Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
	}

	void MathF_NULL::ResetVector2Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
	}

	void MathF_NULL::ResetVector2Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
	}

	void MathF_NULL::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_NULL::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_NULL::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_NULL::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_NULL::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_NULL::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_NULL::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_NULL::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_NULL::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_NULL::Vector2MulImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
	}

	void MathF_NULL::Vector2MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
	}

	void MathF_NULL::Vector2MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
	}

	void MathF_NULL::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_NULL::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_NULL::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_NULL::Vector2DivImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	void MathF_NULL::Vector2DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	void MathF_NULL::Vector2DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	float MathF_NULL::Vector2MagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		return std::sqrt(xSq + ySq);
	}

	float MathF_NULL::Vector2SqMagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		return xSq + ySq;
	}

	double MathF_NULL::Vector2MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		return std::sqrt(xSq + ySq);
	}

	double MathF_NULL::Vector2SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		return xSq + ySq;
	}

	float MathF_NULL::Vector2MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return std::sqrt((float)(xSq + ySq));
	}

	float MathF_NULL::Vector2SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return (float)(xSq + ySq);
	}

	void MathF_NULL::Vector2NormaliseImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float length = std::sqrt(xSq + ySq);
		vec[0] /= length;
		vec[1] /= length;
	}

	void MathF_NULL::Vector2NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double length = std::sqrt(xSq + ySq);
		vec[0] /= length;
		vec[1] /= length;
	}

	//Vector3 Implementation

	void MathF_NULL::ResetVector3Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
		vec[2] = 0.0f;
	}

	void MathF_NULL::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_NULL::ResetVector3Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
	}

	void MathF_NULL::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_NULL::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_NULL::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_NULL::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_NULL::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_NULL::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_NULL::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_NULL::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_NULL::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_NULL::Vector3MulImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
	}

	void MathF_NULL::Vector3MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
	}

	void MathF_NULL::Vector3MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
	}

	void MathF_NULL::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_NULL::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_NULL::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_NULL::Vector3DivImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	void MathF_NULL::Vector3DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	void MathF_NULL::Vector3DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	float MathF_NULL::Vector3MagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	float MathF_NULL::Vector3SqMagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		return xSq + ySq + zSq;
	}

	double MathF_NULL::Vector3MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	double MathF_NULL::Vector3SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return xSq + ySq + zSq;
	}

	float MathF_NULL::Vector3MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return std::sqrt((float)(xSq + ySq + zSq));
	}

	float MathF_NULL::Vector3SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return (float)(xSq + ySq + zSq);
	}

	void MathF_NULL::Vector3NormaliseImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		float length = std::sqrt(xSq + ySq + zSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
	}

	void MathF_NULL::Vector3NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double length = std::sqrt(xSq + ySq + zSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
	}

	//Vector4 Implementation

	void MathF_NULL::ResetVector4Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
		vec[2] = 0.0f;
		vec[3] = 0.0f;
	}

	void MathF_NULL::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_NULL::ResetVector4Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
		vec[3] = 0;
	}

	void MathF_NULL::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_NULL::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_NULL::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_NULL::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_NULL::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_NULL::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_NULL::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_NULL::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_NULL::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_NULL::Vector4MulImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
	}

	void MathF_NULL::Vector4MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
	}

	void MathF_NULL::Vector4MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
	}

	void MathF_NULL::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_NULL::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_NULL::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_NULL::Vector4DivImpl(float* dst, float* vec, float scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	void MathF_NULL::Vector4DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	void MathF_NULL::Vector4DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	float MathF_NULL::Vector4MagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		float wSq = vec[3] * vec[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	float MathF_NULL::Vector4SqMagnitudeImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		float wSq = vec[3] * vec[3];
		return xSq + ySq + zSq + wSq;
	}

	double MathF_NULL::Vector4MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	double MathF_NULL::Vector4SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF_NULL::Vector4MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return std::sqrt((float)(xSq + ySq + zSq + wSq));
	}

	float MathF_NULL::Vector4SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return (float)(xSq + ySq + zSq + wSq);
	}

	void MathF_NULL::Vector4NormaliseImpl(float* vec)
	{
		float xSq = vec[0] * vec[0];
		float ySq = vec[1] * vec[1];
		float zSq = vec[2] * vec[2];
		float wSq = vec[3] * vec[3];
		float length = std::sqrt(xSq + ySq + zSq + wSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
		vec[3] /= length;
	}

	void MathF_NULL::Vector4NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		double length = std::sqrt(xSq + ySq + zSq + wSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
		vec[3] /= length;
	}
}