// Copyright 2022 - Partow Rayan Rastak - All rights reserved

#include "Display/FrameTime.h"

#include "Math/Math.h"


void FrameTime::Tick()
{
	previousTime = currentTime;
	currentTime = Now();

	// Avoid too big delta times
	realDeltaTime = Math::Min(0.15f, currentTime - previousTime);

	// Apply time dilation
	deltaTime = realDeltaTime * timeDilation;
}

void FrameTime::PostTick()
{
	const float elapsed = Now() - currentTime;
	//Serial.println(elapsed * 1000.f);

	const float extraTimeForFPSCAP = minFrameTime - elapsed;
	if (extraTimeForFPSCAP > 0.0f)
	{
		// Cap FPS with a delay
		delay(i32(extraTimeForFPSCAP * 1000.f));
	}
}
