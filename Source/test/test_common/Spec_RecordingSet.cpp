
#include <unity.h>

#include "RecordingSet.h"


void Record_CanInitialize()
{
	TInlineRecordingSet<200, 20> record{};
	TEST_ASSERT_EQUAL(200, record.GetMaxSamples());
	TEST_ASSERT_EQUAL_FLOAT(10.f, record.GetMaxDuration());

	TEST_ASSERT_EQUAL(0, record.GetNumSamples());
	TEST_ASSERT_EQUAL_FLOAT(0.f, record.GetDuration());
}

void Record_CanAddValue()
{
	TInlineRecordingSet<200, 20> record{};
	record.RecordValue(1.f);

	TEST_ASSERT_EQUAL(1, record.GetNumSamples());
}

void Record_CanGetValue()
{
	TInlineRecordingSet<200, 20> record{};
	record.RecordValue(4.f);
	record.RecordValue(5.f);

	TEST_ASSERT_EQUAL(198, record.GetRealIndex(0));
	TEST_ASSERT_EQUAL(199, record.GetRealIndex(1));
	TEST_ASSERT_EQUAL(0, record.GetRealIndex(2)); // Index loops
	TEST_ASSERT_EQUAL_FLOAT(5.f, record.Get(0).y);
	TEST_ASSERT_EQUAL_FLOAT(4.f, record.Get(1).y);
}

void Process()
{
	UNITY_BEGIN();
	RUN_TEST(Record_CanInitialize);
	RUN_TEST(Record_CanAddValue);
	RUN_TEST(Record_CanGetValue);
	UNITY_END();
}


#ifdef ARDUINO

#include <Arduino.h>
void setup()
{
	// NOTE!!! Wait for >2 secs
	// if board doesn't support software reset via Serial.DTR/RTS
	delay(2000);

	Process();
}

void loop()
{
	delay(500);
}

#else

int main(int argc, char** argv)
{
	Process();
	return 0;
}

#endif