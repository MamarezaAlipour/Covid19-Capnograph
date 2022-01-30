
#pragma once

#include "RecordingSet.h"


class Capnograph;

class AnalysisPattern
{
	Capnograph* cartograph = nullptr;


public:

	AnalysisPattern() {}
	virtual ~AnalysisPattern() {}

	void Setup(Capnograph* inCartograph)
	{
		cartograph = inCartograph;
	}

	virtual bool Analize(const RecordingSet& recording) const = 0;
	virtual void OnTrigger() const {}
};
