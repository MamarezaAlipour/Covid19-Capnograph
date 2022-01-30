// Copyright 2022 - Partow Rayan Rastak - All rights reserved

#pragma once

#include "../Platform.h"
#include "v2.h"
#include "Math.h"


struct v2i
{
	i32 x = 0;
	i32 y = 0;


	v2i() = default;
	constexpr v2i(i32 x, i32 y) : x(x), y(y) {}
	v2i(v2 other)
		: x(Math::RoundToInt(other.x))
		, y(Math::RoundToInt(other.y))
	{}


	const v2i operator-(const v2i& other) const
	{
		return { x - other.x, y - other.y };
	}

	const v2i operator+(const v2i& other) const
	{
		return { x + other.x, y + other.y };
	}

	const v2i operator*(const v2i& other) const
	{
		v2i v(x * other.x, y * other.y);
		return v;
	}
	bool operator==(const v2i& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const v2i& other) const
	{
		return !(operator==(other));
	}

	v2i& operator+=(const v2i& other)
	{
		x = x + other.x;
		y = y + other.y;
		return *this;
	}

	v2i& operator*=(const i32 value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	v2i& operator/=(const i32 value)
	{
		x /= value;
		y /= value;
		return *this;
	}

	const v2i operator*(const i32 aValue) const
	{
		v2i v(x * aValue, y * aValue);
		return v;
	}

	i32 Length() const
	{
		return i32(Math::Sqrt(x * x + y * y));
	}

	constexpr i32 ToLinearOffset(i32 xSize) const
	{
		return x + y * xSize;
	}

	bool IsInBounds(v2i min, v2i max) const
	{
		return x >= min.x && y >= min.y && x < max.x&& y < max.y;
	}

	void Clamp(v2i min, v2i max)
	{
		x = Math::Clamp(x, min.x, max.x);
		y = Math::Clamp(y, min.y, max.y);
	}

	static constexpr v2i Zero() { return { 0,0 }; }
	static constexpr v2i One() { return { 1,1 }; }

	static constexpr i32 ManhattanDistance(v2i one, v2i other)
	{
		return Math::Abs(one.x - other.x) + Math::Abs(one.y - other.y);
	}
};
