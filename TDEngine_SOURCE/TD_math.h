#pragma once

namespace math
{
	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;

		float x;
		float y;

		Vector2()
			: x(0.f)
			, y(0.f)
		{
		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{
		}
	};
}

