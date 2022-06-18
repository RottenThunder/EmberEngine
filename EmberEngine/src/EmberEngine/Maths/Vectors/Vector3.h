#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector3f
	{
	public:
		float x, y, z;
	private:
		float w;
	public:
		Vector3f() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3f vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Sub(Vector3f vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Mul(Vector3f vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Div(Vector3f vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline float Magnitude() { return MathF::Vector3Magnitude32(&x); }
		inline float SqMagnitude() { return MathF::Vector3SqMagnitude32(&x); }
	};
	typedef Vector3f Vector3;

	inline Vector3f operator+(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator-(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator*(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator/(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f& operator+= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3f& operator-= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3f& operator*= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3f& operator/= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector3d
	{
	public:
		double x, y, z;
	private:
		double w;
	public:
		Vector3d() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3d vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Sub(Vector3d vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Mul(Vector3d vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Div(Vector3d vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline double Magnitude() { return MathF::Vector3Magnitude64(&x); }
		inline double SqMagnitude() { return MathF::Vector3SqMagnitude64(&x); }
	};

	inline Vector3d operator+(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator-(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator*(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator/(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d& operator+= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3d& operator-= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3d& operator*= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3d& operator/= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector3i
	{
	public:
		int x, y, z;
	private:
		int w;
	public:
		Vector3i() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3i vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Sub(Vector3i vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Mul(Vector3i vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Div(Vector3i vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline float Magnitude32() { return MathF::Vector3Magnitude32(&x); }
		inline float SqMagnitude32() { return MathF::Vector3SqMagnitude32(&x); }
		inline double Magnitude64() { return MathF::Vector3Magnitude64(&x); }
		inline double SqMagnitude64() { return MathF::Vector3SqMagnitude64(&x); }
	};

	inline Vector3i operator+(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator-(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator*(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator/(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i& operator+= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3i& operator-= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3i& operator*= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3i& operator/= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 / vec2; return vec1; }
}