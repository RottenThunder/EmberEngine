#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector2f
	{
	public:
		union
		{
			struct
			{
				float x, y;
			};

			struct
			{
				float Array[2];
			};
		};

		inline void Reset() { MathF::ResetVector2(Array); }
		inline void Add(Vector2f vec) { MathF::Vector2Add(Array, Array, vec.Array); }
		inline void Sub(Vector2f vec) { MathF::Vector2Sub(Array, Array, vec.Array); }
		inline void Mul(Vector2f vec) { MathF::Vector2Mul(Array, Array, vec.Array); }
		inline void Div(Vector2f vec) { MathF::Vector2Div(Array, Array, vec.Array); }
	};

	inline Vector2f operator+(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2f operator-(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2f operator*(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2f operator/(Vector2f vec1, Vector2f vec2) { Vector2f result; MathF::Vector2Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2f& operator+= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2f& operator-= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2f& operator*= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2f& operator/= (Vector2f& vec1, Vector2f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector2d
	{
	public:
		union
		{
			struct
			{
				double x, y;
			};

			struct
			{
				double Array[2];
			};
		};

		inline void Reset() { MathF::ResetVector2(Array); }
		inline void Add(Vector2d vec) { MathF::Vector2Add(Array, Array, vec.Array); }
		inline void Sub(Vector2d vec) { MathF::Vector2Sub(Array, Array, vec.Array); }
		inline void Mul(Vector2d vec) { MathF::Vector2Mul(Array, Array, vec.Array); }
		inline void Div(Vector2d vec) { MathF::Vector2Div(Array, Array, vec.Array); }
	};

	inline Vector2d operator+(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2d operator-(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2d operator*(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2d operator/(Vector2d vec1, Vector2d vec2) { Vector2d result; MathF::Vector2Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2d& operator+= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2d& operator-= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2d& operator*= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2d& operator/= (Vector2d& vec1, Vector2d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector2i
	{
	public:
		union
		{
			struct
			{
				int x, y;
			};

			struct
			{
				int Array[2];
			};
		};

		inline void Reset() { MathF::ResetVector2(Array); }
		inline void Add(Vector2i vec) { MathF::Vector2Add(Array, Array, vec.Array); }
		inline void Sub(Vector2i vec) { MathF::Vector2Sub(Array, Array, vec.Array); }
		inline void Mul(Vector2i vec) { MathF::Vector2Mul(Array, Array, vec.Array); }
		inline void Div(Vector2i vec) { MathF::Vector2Div(Array, Array, vec.Array); }
	};

	inline Vector2i operator+(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2i operator-(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2i operator*(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2i operator/(Vector2i vec1, Vector2i vec2) { Vector2i result; MathF::Vector2Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector2i& operator+= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector2i& operator-= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector2i& operator*= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector2i& operator/= (Vector2i& vec1, Vector2i vec2) { vec1 = vec1 / vec2; return vec1; }
}