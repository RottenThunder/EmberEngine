#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector4f
	{
	public:
		float x, y, z, w;
	public:
		Vector4f() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4f vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Sub(Vector4f vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Mul(Vector4f vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Div(Vector4f vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline float Magnitude() { return MathF::Vector4Magnitude32(&x); }
		inline float SqMagnitude() { return MathF::Vector4SqMagnitude32(&x); }
	};
	typedef Vector4f Vector4;

	inline Vector4f operator+(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator-(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator*(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator/(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f& operator+= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4f& operator-= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4f& operator*= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4f& operator/= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector4d
	{
	public:
		double x, y, z, w;
	public:
		Vector4d() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4d vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Sub(Vector4d vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Mul(Vector4d vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Div(Vector4d vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline double Magnitude() { return MathF::Vector4Magnitude64(&x); }
		inline double SqMagnitude() { return MathF::Vector4SqMagnitude64(&x); }
	};

	inline Vector4d operator+(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator-(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator*(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator/(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d& operator+= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4d& operator-= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4d& operator*= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4d& operator/= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector4i
	{
	public:
		int x, y, z, w;
	public:
		Vector4i() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4i vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Sub(Vector4i vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Mul(Vector4i vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Div(Vector4i vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline float Magnitude32() { return MathF::Vector4Magnitude32(&x); }
		inline float SqMagnitude32() { return MathF::Vector4SqMagnitude32(&x); }
		inline double Magnitude64() { return MathF::Vector4Magnitude64(&x); }
		inline double SqMagnitude64() { return MathF::Vector4SqMagnitude64(&x); }
	};

	inline Vector4i operator+(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator-(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator*(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator/(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i& operator+= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4i& operator-= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4i& operator*= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4i& operator/= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 / vec2; return vec1; }
}