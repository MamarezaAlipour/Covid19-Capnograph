
#pragma once

#include "Display/Display.h"
#include "Display/Graph.h"


class Capnograph;

class UI
{
public:

	Display display;
	Graph graph;

	const float graphDuration = 10.f;


	void Start();

	void Draw(Capnograph& capnograph);

	void SetCurrentCO2(float value) {}
	void UpdateRecording(const RecordingSet& recording) {}

private:

	void DrawCurrentValue(Capnograph& capnograph);

	void DrawBreathsPerSecond(Capnograph& capnograph);
};
