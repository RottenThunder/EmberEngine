#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Vector3f
	{
	public:
		union
		{
			struct
			{
				float x, y, z;
			};

			struct
			{
				float Array[3];
			};
		};

		inline void Reset() { MathF::ResetVector3(Array); }
		inline void Add(Vector3f vec) { MathF::Vector3Add(Array, Array, vec.Array); }
		inline void Sub(Vector3f vec) { MathF::Vector3Sub(Array, Array, vec.Array); }
		inline void Mul(Vector3f vec) { MathF::Vector3Mul(Array, Array, vec.Array); }
		inline void Div(Vector3f vec) { MathF::Vector3Div(Array, Array, vec.Array); }
	};

	inline Vector3f operator+(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3f operator-(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3f operator*(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3f operator/(Vector3f vec1, Vector3f vec2) { Vector3f result; MathF::Vector3Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3f& operator+= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3f& operator-= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3f& operator*= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3f& operator/= (Vector3f& vec1, Vector3f vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector3d
	{
	public:
		union
		{
			struct
			{
				double x, y, z;
			};

			struct
			{
				double Array[3];
			};
		};

		inline void Reset() { MathF::ResetVector3(Array); }
		inline void Add(Vector3d vec) { MathF::Vector3Add(Array, Array, vec.Array); }
		inline void Sub(Vector3d vec) { MathF::Vector3Sub(Array, Array, vec.Array); }
		inline void Mul(Vector3d vec) { MathF::Vector3Mul(Array, Array, vec.Array); }
		inline void Div(Vector3d vec) { MathF::Vector3Div(Array, Array, vec.Array); }
	};

	inline Vector3d operator+(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3d operator-(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3d operator*(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3d operator/(Vector3d vec1, Vector3d vec2) { Vector3d result; MathF::Vector3Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3d& operator+= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3d& operator-= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3d& operator*= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3d& operator/= (Vector3d& vec1, Vector3d vec2) { vec1 = vec1 / vec2; return vec1; }

	class Vector3i
	{
	public:
		union
		{
			struct
			{
				int x, y, z;
			};

			struct
			{
				int Array[3];
			};
		};

		inline void Reset() { MathF::ResetVector3(Array); }
		inline void Add(Vector3i vec) { MathF::Vector3Add(Array, Array, vec.Array); }
		inline void Sub(Vector3i vec) { MathF::Vector3Sub(Array, Array, vec.Array); }
		inline void Mul(Vector3i vec) { MathF::Vector3Mul(Array, Array, vec.Array); }
		inline void Div(Vector3i vec) { MathF::Vector3Div(Array, Array, vec.Array); }
	};

	inline Vector3i operator+(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Add(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3i operator-(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Sub(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3i operator*(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Mul(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3i operator/(Vector3i vec1, Vector3i vec2) { Vector3i result; MathF::Vector3Div(result.Array, vec1.Array, vec2.Array); return result; }
	inline Vector3i& operator+= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 + vec2; return vec1; }
	inline Vector3i& operator-= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 - vec2; return vec1; }
	inline Vector3i& operator*= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 * vec2; return vec1; }
	inline Vector3i& operator/= (Vector3i& vec1, Vector3i vec2) { vec1 = vec1 / vec2; return vec1; }
}