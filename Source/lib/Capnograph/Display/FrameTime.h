// Copyright 2020 Miguel Fernandez Arce - All rights reserved
#pragma once

#include <Arduino.h>

#include "Platform.h"


struct FrameTime
{
protected:

	float previousTime;
	float currentTime;

	float realDeltaTime = 0.f;
	float deltaTime = 0.f;

	float timeDilation = 1.f;

	// Value of 1/FPS_CAP
	float minFrameTime;


public:

	FrameTime()
		: previousTime{ Now() }
		, currentTime{ previousTime }
	{}

	void Tick();

	void PostTick();

	void SetFPSCap(u32 maxFPS) { minFrameTime = 1.f / maxFPS; }

	void SetTimeDilation(float newTimeDilation) { timeDilation = newTimeDilation; }

	float GetDeltaTime() const { return deltaTime; }
	i32 GetFPS() const { return i32(1.f / deltaTime); }

	static float Now()
	{
		return 0.001f * millis();
	}
};
