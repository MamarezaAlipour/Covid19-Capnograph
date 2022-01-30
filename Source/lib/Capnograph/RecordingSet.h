
#pragma once

#include "Platform.h"
#include "Math/v2.h"


struct RecordingSet
{
protected:
	const float timePerSample;
	const i32 maxSize;
	i32 firstIndex = 0;
	i32 size = 0;
	float* valuesPtr = nullptr;


	RecordingSet(float timePerSample, i32 maxSize)
		: timePerSample{ timePerSample }
		, maxSize{ maxSize }
	{}

public:

	void RecordValue(float value);

	float GetMaximum() const { return 0.f; }
	float GetMinimum() const { return 0.f; }

	float GetNumSamples() const { return size; }
	float GetMaxSamples() const { return maxSize; }
	float GetDuration() const { return timePerSample * size; }
	float GetMaxDuration() const { return timePerSample * maxSize; }

	v2 Get(i32 index) const;
	float GetValue(i32 index) const;
	i32 GetRealIndex(i32 index) const;

	float GetSize() const { return size; }
	float GetFirstIndex() const { return firstIndex; }
};


template<i32 samples, i32 samplesPerSecond>
struct TInlineRecordingSet : public RecordingSet
{
protected:

	float values[samples];


public:

	TInlineRecordingSet() : RecordingSet(1.f / samplesPerSecond, samples)
	{
		valuesPtr = values;
	}
	TInlineRecordingSet(TInlineRecordingSet&& other) = default;
};

struct DynamicRecordingSet : public RecordingSet
{
public:

	DynamicRecordingSet(float timePerSample, i32 maxSize)
		: RecordingSet(timePerSample, maxSize)
	{
		valuesPtr = new float[maxSize];
	}

	~DynamicRecordingSet()
	{
		delete[] valuesPtr;
	}
};
