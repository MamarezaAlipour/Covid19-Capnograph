// Copyright 2022 - Partow Rayan Rastak - All rights reserved

#pragma once

#include "Math.h"
#include "../Platform.h"


class v2
{
public:

	float x = 0.f;
	float y = 0.f;


	v2() = default;
	constexpr v2(float x, float y) : x(x), y(y) {}
	v2(struct v2i other);


	const v2 operator+(const v2& other) const
	{
		return { x + other.x, y + other.y };
	}

	const v2 operator-(const v2& other) const
	{
		return { x - other.x, y - other.y };
	}

	const v2 operator-() const
	{
		return operator*(-1.f);
	}

	const v2 operator*(const v2& other) const
	{
		v2 v(x * other.x, y * other.y);
		return v;
	}

	v2& operator+=(const v2& other)
	{
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	v2& operator-=(const v2& other)
	{
		x = x - other.x;
		y = y - other.y;
		return *this;
	}

	v2& operator*=(const v2 other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	v2& operator*=(const float value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	v2& operator/=(const float value)
	{
		x /= value;
		y /= value;
		return *this;
	}

	constexpr v2 operator*(const float value) const
	{
		return { x * value, y * value };
	}

	float Length() const
	{
		return Math::Sqrt(x * x + y * y);
	}

	void Normalize()
	{
		const float length = Length();
		if (length > 0.f)
		{
			*this /= length;
		}
	}

	static constexpr v2 Zero() { return { 0.f, 0.f }; }
	static constexpr v2 One() { return { 1.f, 1.f }; }

	static constexpr v2 Abs(v2 v)
	{
		return { Math::Abs(v.x), Math::Abs(v.y) };
	}

	static constexpr v2 Min(v2 one, v2 other)
	{
		return { Math::Min(one.x, other.x), Math::Min(one.y, other.y) };
	}

	static constexpr v2 Clamp(v2 target, v2 min, v2 max)
	{
		return {
			Math::Clamp(target.x, min.x, max.x),
			Math::Clamp(target.y, min.y, max.y)
		};
	}
};
