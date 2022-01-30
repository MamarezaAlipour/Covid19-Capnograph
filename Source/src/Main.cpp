
#include <Arduino.h>

#include "Capnograph.h"


Capnograph captograph{};

void setup()
{
	Serial.begin(9600);
	captograph.Setup();
}

void loop()
{
	captograph.Loop();
}
