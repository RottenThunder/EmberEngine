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
		Vector3f(float xf, float yf, float zf) : x(xf), y(yf), z(zf), w(0.0f) {}

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3f vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Subtract(Vector3f vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector3f vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Multiply(float scalar) { MathF::Vector3Mul(&x, &x, scalar); }
		inline void Divide(Vector3f vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline void Divide(float scalar) { MathF::Vector3Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector3Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector3SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector3Normalise(&x); }
		inline float Dot(Vector3f vec) { return MathF::Vector3Dot(&x, &vec.x); }
		inline Vector3f Cross(Vector3f vec) { Vector3f result; MathF::Vector3Cross(&result.x, &x, &vec.x); return result; }
	};

	typedef Vector3f Vector3;

	Vector3f V3Normalise(Vector3f vec);
	float V3Dot(Vector3f vec1, Vector3f vec2);
	Vector3f V3Cross(Vector3f vec1, Vector3f vec2);

	inline Vector3f operator+(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator-(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator*(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator*(Vector3f vec, float scalar) { Vector3f result; MathF::Vector3Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector3f operator/(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3f operator/(Vector3f vec, float scalar) { Vector3f result; MathF::Vector3Div(&result.x, &vec.x, scalar); return result; }
	inline Vector3f& operator+= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3f& operator-= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3f& operator*= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3f& operator*= (Vector3f& vec, float scalar) { vec = vec * scalar; return vec; }
	inline Vector3f& operator/= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector3f& operator/= (Vector3f& vec, float scalar) { vec = vec / scalar; return vec; }

	class Vector3d
	{
	public:
		double x, y, z;
	private:
		double w;
	public:
		Vector3d() { MathF::ResetVector4(&x); }
		Vector3d(double xd, double yd, double zd) : x(xd), y(yd), z(zd), w(0.0) {}

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3d vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Subtract(Vector3d vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector3d vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Multiply(double scalar) { MathF::Vector3Mul(&x, &x, scalar); }
		inline void Divide(Vector3d vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline void Divide(double scalar) { MathF::Vector3Div(&x, &x, scalar); }
		inline double Magnitude() { return MathF::Vector3Magnitude(&x); }
		inline double SqMagnitude() { return MathF::Vector3SqMagnitude(&x); }
		inline void Normalise() { MathF::Vector3Normalise(&x); }
		inline double Dot(Vector3d vec) { return MathF::Vector3Dot(&x, &vec.x); }
		inline Vector3d Cross(Vector3d vec) { Vector3d result; MathF::Vector3Cross(&result.x, &x, &vec.x); return result; }
	};

	Vector3d V3Normalise(Vector3d vec);
	double V3Dot(Vector3d vec1, Vector3d vec2);
	Vector3d V3Cross(Vector3d vec1, Vector3d vec2);

	inline Vector3d operator+(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator-(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator*(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator*(Vector3d vec, double scalar) { Vector3d result; MathF::Vector3Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector3d operator/(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3d operator/(Vector3d vec, double scalar) { Vector3d result; MathF::Vector3Div(&result.x, &vec.x, scalar); return result; }
	inline Vector3d& operator+= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3d& operator-= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3d& operator*= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3d& operator*= (Vector3d& vec, double scalar) { vec = vec * scalar; return vec; }
	inline Vector3d& operator/= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector3d& operator/= (Vector3d& vec, double scalar) { vec = vec / scalar; return vec; }

	class Vector3i
	{
	public:
		int x, y, z;
	private:
		int w;
	public:
		Vector3i() { MathF::ResetVector4(&x); }
		Vector3i(int xi, int yi, int zi) : x(xi), y(yi), z(zi), w(0) {}

		inline void Reset() { MathF::ResetVector3(&x); }
		inline void Add(Vector3i vec) { MathF::Vector3Add(&x, &x, &vec.x); }
		inline void Subtract(Vector3i vec) { MathF::Vector3Sub(&x, &x, &vec.x); }
		inline void Multiply(Vector3i vec) { MathF::Vector3Mul(&x, &x, &vec.x); }
		inline void Multiply(int scalar) { MathF::Vector3Mul(&x, &x, scalar); }
		inline void Divide(Vector3i vec) { MathF::Vector3Div(&x, &x, &vec.x); }
		inline void Divide(int scalar) { MathF::Vector3Div(&x, &x, scalar); }
		inline float Magnitude() { return MathF::Vector3Magnitude(&x); }
		inline float SqMagnitude() { return MathF::Vector3SqMagnitude(&x); }
	};

	inline Vector3i operator+(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Add(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator-(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Sub(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator*(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Mul(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator*(Vector3i vec, int scalar) { Vector3i result; MathF::Vector3Mul(&result.x, &vec.x, scalar); return result; }
	inline Vector3i operator/(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Div(&result.x, &vec1.x, &vec2.x); return result; }
	inline Vector3i operator/(Vector3i vec, int scalar) { Vector3i result; MathF::Vector3Div(&result.x, &vec.x, scalar); return result; }
	inline Vector3i& operator+= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3i& operator-= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3i& operator*= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3i& operator*= (Vector3i& vec, int scalar) { vec = vec * scalar; return vec; }
	inline Vector3i& operator/= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 / vec2; return vec1; }
	inline Vector3i& operator/= (Vector3i& vec, int scalar) { vec = vec / scalar; return vec; }
}