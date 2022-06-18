#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector2f
	{
	public:
		float x, y;
	private:
		float z, w;
	public:
		Vector2f() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector2(&x); }
		inline void Add(Vector2f vec) { MathF::Vector2Add(&x, &x, &vec.x); }
		inline void Sub(Vector2f vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Mul(Vector2f vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Div(Vector2f vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline float Magnitude() { return MathF::Vector2Magnitude32(&x); }
		inline float SqMagnitude() { return MathF::Vector2SqMagnitude32(&x); }
	};
	typedef Vector2f Vector2;

	inline Vector2f operator+(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator-(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator*(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator/(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f& operator+= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2f& operator-= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2f& operator*= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2f& operator/= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector2d
	{
	public:
		double x, y;
	public:
		Vector2d() { MathF::ResetVector2(&x); }

		inline void Reset() { MathF::ResetVector2(&x); }
		inline void Add(Vector2d vec) { MathF::Vector2Add(&x, &x, &vec.x); }
		inline void Sub(Vector2d vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Mul(Vector2d vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Div(Vector2d vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline double Magnitude() { return MathF::Vector2Magnitude64(&x); }
		inline double SqMagnitude() { return MathF::Vector2SqMagnitude64(&x); }
	};

	inline Vector2d operator+(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator-(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator*(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator/(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d& operator+= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2d& operator-= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2d& operator*= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2d& operator/= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector2i
	{
	public:
		int x, y;
	private:
		int z, w;
	public:
		Vector2i() { MathF::ResetVector4(&x); }

		inline void Reset() { MathF::ResetVector2(&x); }
		inline void Add(Vector2i vec) { MathF::Vector2Add(&x, &x, &vec.x); }
		inline void Sub(Vector2i vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Mul(Vector2i vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Div(Vector2i vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline float Magnitude32() { return MathF::Vector2Magnitude32(&x); }
		inline float SqMagnitude32() { return MathF::Vector2SqMagnitude32(&x); }
		inline double Magnitude64() { return MathF::Vector2Magnitude64(&x); }
		inline double SqMagnitude64() { return MathF::Vector2SqMagnitude64(&x); }
	};

	inline Vector2i operator+(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator-(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator*(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator/(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i& operator+= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2i& operator-= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2i& operator*= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2i& operator/= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 / vec2; return vec1; }
}