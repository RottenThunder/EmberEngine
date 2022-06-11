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

		void Reset() { MathF::ResetVector2(Array); }
	};

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

		void Reset() { MathF::ResetVector2(Array); }
	};

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

		void Reset() { MathF::ResetVector2(Array); }
	};
}