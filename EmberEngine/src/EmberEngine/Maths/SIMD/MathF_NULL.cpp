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

	float MathF_NULL::Vector3DotImpl(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		float zSq = vec1[2] * vec2[2];
		return xSq + ySq + zSq;
	}

	double MathF_NULL::Vector3DotImpl(double* vec1, double* vec2)
	{
		double xSq = vec1[0] * vec2[0];
		double ySq = vec1[1] * vec2[1];
		double zSq = vec1[2] * vec2[2];
		return xSq + ySq + zSq;
	}

	void MathF_NULL::Vector3CrossImpl(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
		dst[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
		dst[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];
	}

	void MathF_NULL::Vector3CrossImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
		dst[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
		dst[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];
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

	//Matrix4x4 Implementation

	void MathF_NULL::ResetMatrix4x4Impl(float* matrix)
	{
		matrix[0] = 0.0f;
		matrix[1] = 0.0f;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = 0.0f;
		matrix[5] = 0.0f;
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 0.0f;
		matrix[9] = 0.0f;
		matrix[10] = 0.0f;
		matrix[11] = 0.0f;
		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 0.0f;
	}

	void MathF_NULL::SetToIdentityImpl(float* matrix)
	{
		matrix[0] = 1.0f;
		matrix[1] = 0.0f;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = 0.0f;
		matrix[5] = 1.0f;
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 0.0f;
		matrix[9] = 0.0f;
		matrix[10] = 1.0f;
		matrix[11] = 0.0f;
		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}

	void MathF_NULL::MultiplyMatrix4x4Impl(float* dst, float* matrix1, float* matrix2)
	{
		float intermediate[64];

		intermediate[0] = matrix1[0] * matrix2[0];
		intermediate[1] = matrix1[1] * matrix2[0];
		intermediate[2] = matrix1[2] * matrix2[0];
		intermediate[3] = matrix1[3] * matrix2[0];
		intermediate[4] = matrix1[4] * matrix2[1];
		intermediate[5] = matrix1[5] * matrix2[1];
		intermediate[6] = matrix1[6] * matrix2[1];
		intermediate[7] = matrix1[7] * matrix2[1];
		intermediate[8] = matrix1[8] * matrix2[2];
		intermediate[9] = matrix1[9] * matrix2[2];
		intermediate[10] = matrix1[10] * matrix2[2];
		intermediate[11] = matrix1[11] * matrix2[2];
		intermediate[12] = matrix1[12] * matrix2[3];
		intermediate[13] = matrix1[13] * matrix2[3];
		intermediate[14] = matrix1[14] * matrix2[3];
		intermediate[15] = matrix1[15] * matrix2[3];

		intermediate[16] = matrix1[0] * matrix2[4];
		intermediate[17] = matrix1[1] * matrix2[4];
		intermediate[18] = matrix1[2] * matrix2[4];
		intermediate[19] = matrix1[3] * matrix2[4];
		intermediate[20] = matrix1[4] * matrix2[5];
		intermediate[21] = matrix1[5] * matrix2[5];
		intermediate[22] = matrix1[6] * matrix2[5];
		intermediate[23] = matrix1[7] * matrix2[5];
		intermediate[24] = matrix1[8] * matrix2[6];
		intermediate[25] = matrix1[9] * matrix2[6];
		intermediate[26] = matrix1[10] * matrix2[6];
		intermediate[27] = matrix1[11] * matrix2[6];
		intermediate[28] = matrix1[12] * matrix2[7];
		intermediate[29] = matrix1[13] * matrix2[7];
		intermediate[30] = matrix1[14] * matrix2[7];
		intermediate[31] = matrix1[15] * matrix2[7];

		intermediate[32] = matrix1[0] * matrix2[8];
		intermediate[33] = matrix1[1] * matrix2[8];
		intermediate[34] = matrix1[2] * matrix2[8];
		intermediate[35] = matrix1[3] * matrix2[8];
		intermediate[36] = matrix1[4] * matrix2[9];
		intermediate[37] = matrix1[5] * matrix2[9];
		intermediate[38] = matrix1[6] * matrix2[9];
		intermediate[39] = matrix1[7] * matrix2[9];
		intermediate[40] = matrix1[8] * matrix2[10];
		intermediate[41] = matrix1[9] * matrix2[10];
		intermediate[42] = matrix1[10] * matrix2[10];
		intermediate[43] = matrix1[11] * matrix2[10];
		intermediate[44] = matrix1[12] * matrix2[11];
		intermediate[45] = matrix1[13] * matrix2[11];
		intermediate[46] = matrix1[14] * matrix2[11];
		intermediate[47] = matrix1[15] * matrix2[11];

		intermediate[48] = matrix1[0] * matrix2[12];
		intermediate[49] = matrix1[1] * matrix2[12];
		intermediate[50] = matrix1[2] * matrix2[12];
		intermediate[51] = matrix1[3] * matrix2[12];
		intermediate[52] = matrix1[4] * matrix2[13];
		intermediate[53] = matrix1[5] * matrix2[13];
		intermediate[54] = matrix1[6] * matrix2[13];
		intermediate[55] = matrix1[7] * matrix2[13];
		intermediate[56] = matrix1[8] * matrix2[14];
		intermediate[57] = matrix1[9] * matrix2[14];
		intermediate[58] = matrix1[10] * matrix2[14];
		intermediate[59] = matrix1[11] * matrix2[14];
		intermediate[60] = matrix1[12] * matrix2[15];
		intermediate[61] = matrix1[13] * matrix2[15];
		intermediate[62] = matrix1[14] * matrix2[15];
		intermediate[63] = matrix1[15] * matrix2[15];

		dst[0] = intermediate[0] + intermediate[4] + intermediate[8] + intermediate[12];
		dst[1] = intermediate[1] + intermediate[5] + intermediate[9] + intermediate[13];
		dst[2] = intermediate[2] + intermediate[6] + intermediate[10] + intermediate[14];
		dst[3] = intermediate[3] + intermediate[7] + intermediate[11] + intermediate[15];

		dst[4] = intermediate[16] + intermediate[20] + intermediate[24] + intermediate[28];
		dst[5] = intermediate[17] + intermediate[21] + intermediate[25] + intermediate[29];
		dst[6] = intermediate[18] + intermediate[22] + intermediate[26] + intermediate[30];
		dst[7] = intermediate[19] + intermediate[23] + intermediate[27] + intermediate[31];

		dst[8] = intermediate[32] + intermediate[36] + intermediate[40] + intermediate[44];
		dst[9] = intermediate[33] + intermediate[37] + intermediate[41] + intermediate[45];
		dst[10] = intermediate[34] + intermediate[38] + intermediate[42] + intermediate[46];
		dst[11] = intermediate[35] + intermediate[39] + intermediate[43] + intermediate[47];

		dst[12] = intermediate[48] + intermediate[52] + intermediate[56] + intermediate[60];
		dst[13] = intermediate[49] + intermediate[53] + intermediate[57] + intermediate[61];
		dst[14] = intermediate[50] + intermediate[54] + intermediate[58] + intermediate[62];
		dst[15] = intermediate[51] + intermediate[55] + intermediate[59] + intermediate[63];
	}

	void MathF_NULL::SetToTranslationImpl(float* matrix, float* vec2)
	{
		matrix[0] = 1.0f;
		matrix[1] = 0.0f;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = 0.0f;
		matrix[5] = 1.0f;
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 0.0f;
		matrix[9] = 0.0f;
		matrix[10] = 1.0f;
		matrix[11] = 0.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}

	void MathF_NULL::SetToScaleImpl(float* matrix, float* vec2)
	{
		matrix[0] = vec2[0];
		matrix[1] = 0.0f;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = 0.0f;
		matrix[5] = vec2[1];
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 0.0f;
		matrix[9] = 0.0f;
		matrix[10] = 1.0f;
		matrix[11] = 0.0f;
		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}

	void MathF_NULL::SetToRotationImpl(float* matrix, float radians)
	{
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		matrix[0] = cosAngle;
		matrix[1] = sinAngle;
		matrix[2] = 0.0f;
		matrix[3] = 0.0f;
		matrix[4] = -sinAngle;
		matrix[5] = cosAngle;
		matrix[6] = 0.0f;
		matrix[7] = 0.0f;
		matrix[8] = 0.0f;
		matrix[9] = 0.0f;
		matrix[10] = 1.0f;
		matrix[11] = 0.0f;
		matrix[12] = 0.0f;
		matrix[13] = 0.0f;
		matrix[14] = 0.0f;
		matrix[15] = 1.0f;
	}

	void MathF_NULL::SetToTranslationWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[15] = 1.0f;
	}

	void MathF_NULL::SetToScaleWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = vec2[0];
		matrix[5] = vec2[1];
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_NULL::SetToRotationWithoutResetImpl(float* matrix, float radians)
	{
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		matrix[0] = cosAngle;
		matrix[1] = sinAngle;
		matrix[4] = -sinAngle;
		matrix[5] = cosAngle;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}
}