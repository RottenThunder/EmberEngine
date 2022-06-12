#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector4f
	{
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};

			struct
			{
				float Array[4];
			};
		};

		inline void Reset() { MathF::ResetVector4(Array); }
		inline void Add(Vector4f vec) { MathF::Vector4Add(Array, Array, vec.Array); }
		inline void Sub(Vector4f vec) { MathF::Vector4Sub(Array, Array, vec.Array); }
		inline void Mul(Vector4f vec) { MathF::Vector4Mul(Array, Array, vec.Array); }
		inline void Div(Vector4f vec) { MathF::Vector4Div(Array, Array, vec.Array); }
	};

	inline Vector4f operator+(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4f operator-(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4f operator*(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4f operator/(Vector4f vec1, Vector4f vec2) { Vector4f result; MathF::Vector4Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4f& operator+= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4f& operator-= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4f& operator*= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4f& operator/= (Vector4f& vec1, Vector4f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector4d
	{
	public:
		union
		{
			struct
			{
				double x, y, z, w;
			};

			struct
			{
				double Array[4];
			};
		};

		inline void Reset() { MathF::ResetVector4(Array); }
		inline void Add(Vector4d vec) { MathF::Vector4Add(Array, Array, vec.Array); }
		inline void Sub(Vector4d vec) { MathF::Vector4Sub(Array, Array, vec.Array); }
		inline void Mul(Vector4d vec) { MathF::Vector4Mul(Array, Array, vec.Array); }
		inline void Div(Vector4d vec) { MathF::Vector4Div(Array, Array, vec.Array); }
	};

	inline Vector4d operator+(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4d operator-(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4d operator*(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4d operator/(Vector4d vec1, Vector4d vec2) { Vector4d result; MathF::Vector4Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4d& operator+= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4d& operator-= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4d& operator*= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4d& operator/= (Vector4d& vec1, Vector4d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector4i
	{
	public:
		union
		{
			struct
			{
				int x, y, z, w;
			};

			struct
			{
				int Array[4];
			};
		};

		inline void Reset() { MathF::ResetVector4(Array); }
		inline void Add(Vector4i vec) { MathF::Vector4Add(Array, Array, vec.Array); }
		inline void Sub(Vector4i vec) { MathF::Vector4Sub(Array, Array, vec.Array); }
		inline void Mul(Vector4i vec) { MathF::Vector4Mul(Array, Array, vec.Array); }
		inline void Div(Vector4i vec) { MathF::Vector4Div(Array, Array, vec.Array); }
	};

	inline Vector4i operator+(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4i operator-(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4i operator*(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4i operator/(Vector4i vec1, Vector4i vec2) { Vector4i result; MathF::Vector4Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector4i& operator+= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector4i& operator-= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector4i& operator*= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector4i& operator/= (Vector4i& vec1, Vector4i vec2) { vec1 = vec1 / vec2; return vec1; }
}