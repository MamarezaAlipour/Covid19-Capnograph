
#pragma once


class SensorAdapter {};

class Sensor
{
public:
	float lastValue = 0.f;

	Sensor() {}
	virtual ~Sensor() {}
	virtual void Record(RecordingSet& record) = 0;
};

class Sensor_SprintIR : public Sensor
{
	char printBuffer[33];
	HardwareSerial sensorSerial{ 2 };

public:

	Sensor_SprintIR() : Sensor()
	{
		sensorSerial.begin(9600);
	}

	virtual void Record(RecordingSet& record) override
	{
		// Wait for a new chain of values
		while (sensorSerial.read() != 'Z') {}

		u32 co2filteredRX = sensorSerial.parseInt();
		u32 co2rawRX = sensorSerial.parseInt();

		// Record value
		lastValue = float(co2rawRX) / 1000.f;
		record.RecordValue(lastValue);
	}
};

class Sensor_MockAnalog : public Sensor
{
	static constexpr u32 pin = 34;
	static constexpr float minValue = 0.f;
	static constexpr float maxValue = 60.f;


public:

	virtual void Record(RecordingSet& record) override
	{
		// Read signal 4 times and average value
		u16 value = 0;
		for (u8 i = 0; i < 4; ++i)
		{
			value += analogRead(pin);
			delayMicroseconds(50);
		}
		value /= 4;

		// Record value
		const float value01 = float(value) / 4096;
		lastValue = minValue + (value01 * (maxValue - minValue));

		record.RecordValue(lastValue);
	}
};
