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
		inline void Subtract(Vector2f vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector2f vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Multiply(float scalar) { MathF::Vector2Mul(&x, &x, scalar); }
		inline void Divide(Vector2f vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline void Divide(float scalar) { MathF::Vector2Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector2Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector2SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector2Normalise(&x); }
	};

	typedef Vector2f Vector2;

	Vector2f V2Normalise(Vector2f vec);

	inline Vector2f operator+(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator-(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator*(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator*(Vector2f vec, float scalar) { Vector2f result; MathF::Vector2Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector2f operator/(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2f operator/(Vector2f vec, float scalar) { Vector2f result; MathF::Vector2Div(&result.x, &vec.x, scalar); return result; }
	inline Vector2f& operator+= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2f& operator-= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2f& operator*= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2f& operator*= (Vector2f& vec, float scalar) { vec = vec * scalar; return vec; }
	inline Vector2f& operator/= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector2f& operator/= (Vector2f& vec, float scalar) { vec = vec / scalar; return vec; }

	class Vector2d
	{
	public:
		double x, y;
	public:
		Vector2d() { MathF::ResetVector2(&x); }

		inline void Reset() { MathF::ResetVector2(&x); }
		inline void Add(Vector2d vec) { MathF::Vector2Add(&x, &x, &vec.x); }
		inline void Subtract(Vector2d vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector2d vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Multiply(double scalar) { MathF::Vector2Mul(&x, &x, scalar); }
		inline void Divide(Vector2d vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline void Divide(double scalar) { MathF::Vector2Div(&x, &x, scalar); }
		inline double Magnitude() { return MathF::Vector2Magnitude(&x); }
		inline double SqMagnitude() { return MathF::Vector2SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector2Normalise(&x); }
	};

	Vector2d V2Normalise(Vector2d vec);

	inline Vector2d operator+(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator-(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator*(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator*(Vector2d vec, double scalar) { Vector2d result; MathF::Vector2Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector2d operator/(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2d operator/(Vector2d vec, double scalar) { Vector2d result; MathF::Vector2Div(&result.x, &vec.x, scalar); return result; }
	inline Vector2d& operator+= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2d& operator-= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2d& operator*= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2d& operator*= (Vector2d& vec, double scalar) { vec = vec * scalar; return vec; }
	inline Vector2d& operator/= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector2d& operator/= (Vector2d& vec, double scalar) { vec = vec / scalar; return vec; }

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
		inline void Subtract(Vector2i vec) { MathF::Vector2Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector2i vec) { MathF::Vector2Mul(&x, &x, &vec.x); }
		inline void Multiply(int scalar) { MathF::Vector2Mul(&x, &x, scalar); }
		inline void Divide(Vector2i vec) { MathF::Vector2Div(&x, &x, &vec.x); }
		inline void Divide(int scalar) { MathF::Vector2Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector2Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector2SqMagnitude(&x); }
	};

	inline Vector2i operator+(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator-(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator*(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator*(Vector2i vec, int scalar) { Vector2i result; MathF::Vector2Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector2i operator/(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector2i operator/(Vector2i vec, int scalar) { Vector2i result; MathF::Vector2Div(&result.x, &vec.x, scalar); return result; }
	inline Vector2i& operator+= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2i& operator-= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2i& operator*= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2i& operator*= (Vector2i& vec, int scalar) { vec = vec * scalar; return vec; }
	inline Vector2i& operator/= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector2i& operator/= (Vector2i& vec, int scalar) { vec = vec / scalar; return vec; }
}