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

		void Reset() { MathF::ResetVector3(Array); }
	};

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

		void Reset() { MathF::ResetVector3(Array); }
	};

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

		void Reset() { MathF::ResetVector3(Array); }
	};
}