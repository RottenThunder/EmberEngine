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
		Vector4f(float xf, float yf, float zf, float wf) : x(xf), y(yf), z(zf), w(wf) {}

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4f vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Subract(Vector4f vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector4f vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Multiply(float scalar) { MathF::Vector4Mul(&x, &x, scalar); }
		inline void Divide(Vector4f vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline void Divide(float scalar) { MathF::Vector4Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector4Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector4SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector4Normalise(&x); }
	};

	typedef Vector4f Vector4;

	Vector4f V4Normalise(Vector4f vec);

	inline Vector4f operator+(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator-(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator*(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator*(Vector4f vec, float scalar) { Vector4f result; MathF::Vector4Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector4f operator/(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4f operator/(Vector4f vec, float scalar) { Vector4f result; MathF::Vector4Div(&result.x, &vec.x, scalar); return result; }
	inline Vector4f& operator+= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4f& operator-= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4f& operator*= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4f& operator*= (Vector4f& vec, float scalar) { vec = vec * scalar; return vec; }
	inline Vector4f& operator/= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector4f& operator/= (Vector4f& vec, float scalar) { vec = vec / scalar; return vec; }

	class Vector4d
	{
	public:
		double x, y, z, w;
	public:
		Vector4d() { MathF::ResetVector4(&x); }
		Vector4d(double xd, double yd, double zd, double wd) : x(xd), y(yd), z(zd), w(wd) {}

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4d vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Subtract(Vector4d vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector4d vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Multiply(double scalar) { MathF::Vector4Mul(&x, &x, scalar); }
		inline void Divide(Vector4d vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline void Divide(double scalar) { MathF::Vector4Div(&x, &x, scalar); }
		inline double Magnitude() { return MathF::Vector4Magnitude(&x); }
		inline double SqMagnitude() { return MathF::Vector4SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector4Normalise(&x); }
	};

	Vector4d V4Normalise(Vector4d vec);

	inline Vector4d operator+(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator-(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator*(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator*(Vector4d vec, double scalar) { Vector4d result; MathF::Vector4Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector4d operator/(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4d operator/(Vector4d vec, double scalar) { Vector4d result; MathF::Vector4Div(&result.x, &vec.x, scalar); return result; }
	inline Vector4d& operator+= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4d& operator-= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4d& operator*= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4d& operator*= (Vector4d& vec, double scalar) { vec = vec * scalar; return vec; }
	inline Vector4d& operator/= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector4d& operator/= (Vector4d& vec, double scalar) { vec = vec / scalar; return vec; }

	class Vector4i
	{
	public:
		int x, y, z, w;
	public:
		Vector4i() { MathF::ResetVector4(&x); }
		Vector4i(int xi, int yi, int zi, int wi) : x(xi), y(yi), z(zi), w(wi) {}

		inline void Reset() { MathF::ResetVector4(&x); }
		inline void Add(Vector4i vec) { MathF::Vector4Add(&x, &x, &vec.x); }
		inline void Subtract(Vector4i vec) { MathF::Vector4Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector4i vec) { MathF::Vector4Mul(&x, &x, &vec.x); }
		inline void Multiply(int scalar) { MathF::Vector4Mul(&x, &x, scalar); }
		inline void Divide(Vector4i vec) { MathF::Vector4Div(&x, &x, &vec.x); }
		inline void Divide(int scalar) { MathF::Vector4Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector4Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector4SqMagnitude(&x); }
	};

	inline Vector4i operator+(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator-(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator*(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator*(Vector4i vec, int scalar) { Vector4i result; MathF::Vector4Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector4i operator/(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector4i operator/(Vector4i vec, int scalar) { Vector4i result; MathF::Vector4Div(&result.x, &vec.x, scalar); return result; }
	inline Vector4i& operator+= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4i& operator-= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4i& operator*= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4i& operator*= (Vector4i& vec, int scalar) { vec = vec * scalar; return vec; }
	inline Vector4i& operator/= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector4i& operator/= (Vector4i& vec, int scalar) { vec = vec / scalar; return vec; }
}