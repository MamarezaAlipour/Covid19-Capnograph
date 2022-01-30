
#include "RecordingSet.h"
#include "Math/Math.h"


void RecordingSet::RecordValue(float value)
{
	// Reduce index looping
	firstIndex = (firstIndex > 0 ? firstIndex : maxSize) - 1;
	valuesPtr[firstIndex] = value;

	size = Math::Min(size + 1, maxSize);
}

v2 RecordingSet::Get(i32 index) const
{
	const float time = index * timePerSample;
	const float value = valuesPtr[GetRealIndex(index)];
	return { time, value };
}

float RecordingSet::GetValue(i32 index) const
{
	return valuesPtr[GetRealIndex(index)];
}

i32 RecordingSet::GetRealIndex(i32 index) const
{
	index += firstIndex;
	if (index >= maxSize)
	{
		index -= maxSize;
	}
	return index;
}
