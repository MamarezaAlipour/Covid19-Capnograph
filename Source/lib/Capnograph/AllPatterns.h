
#pragma once

#include "Pattern.h"

class Pattern_Differential : public AnalysisPattern
{
	virtual bool Analize(const RecordingSet& recording) const override
	{
		return false;
	}
	virtual void OnTrigger() const override {}
};


class Pattern_Hipoventilation : public AnalysisPattern
{
	float maxCO2 = 45.f;


	virtual bool Analize(const RecordingSet& recording) const override
	{
		return false;
	}
	virtual void OnTrigger() const override {}
};

class Pattern_Hiperventilation : public AnalysisPattern
{
	float maxCyclesPerMinute = 20.f;


	virtual bool Analize(const RecordingSet& recording) const override
	{
		return false;
	}
	virtual void OnTrigger() const override {}
};