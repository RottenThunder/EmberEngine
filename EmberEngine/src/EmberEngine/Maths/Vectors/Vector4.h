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

		void Reset() { MathF::ResetVector4(Array); }
	};

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

		void Reset() { MathF::ResetVector4(Array); }
	};

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

		void Reset() { MathF::ResetVector4(Array); }
	};
}