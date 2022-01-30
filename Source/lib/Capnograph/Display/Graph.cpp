
#include "Display/Graph.h"
#include "Display/Display.h"
#include "RecordingSet.h"


void Graph::Draw(Display& display, RecordingSet& record)
{
	maxX = record.GetMaxDuration();

	display.DrawRect(position, size, COLOR_BLACK);
	DrawData(display, record);
	DrawAxis(display);
	DrawLabels(display);
}

void Graph::DrawAxis(Display& display) const
{
	DrawLine(display, { 0.f, 0.f }, { 0.f, maxY }, COLOR_WHITE);  // Y
	DrawLine(display, { 0.f, 0.f }, { maxX, 0.f }, COLOR_WHITE);  // X
	DrawLine(display, { 0.f, midYBar }, { maxX, midYBar }, COLOR_ORANGE); // Mid Y
}

void Graph::DrawLabels(Display& display) const
{
	display.SetTextSize(1);
	// Max value
	DrawFloat(display, v2i{ 3, 5 } + ToPixel({ 0.f, maxY }), maxY, COLOR_WHITE, 0);
	// Mid bar line
	DrawFloat(display, v2i{ 3, -2 } + ToPixel({ 0.f, midYBar }), midYBar, COLOR_WHITE, 0);
}

void Graph::DrawData(Display& display, RecordingSet& record) const
{
	if (record.GetSize() <= 1)
	{
		return;
	}

	const i32 maxIndex = record.GetSize() - 1;

	switch (type)
	{
	case GraphType::Line:
	{
		v2 lastPoint{ record.Get(0) };
		for (i32 index = 1; index < maxIndex; ++index)
		{
			const v2 currentPoint{ record.Get(index) };
			DrawLine(display, lastPoint, currentPoint, COLOR_YELLOW);
			lastPoint = currentPoint;
		}
	}
	break;

	case GraphType::Bars:
		for (i32 index = 1; index < maxIndex; ++index)
		{
			const v2 currentPoint{ record.Get(index) };
			DrawLine(display, { currentPoint.x, 0.f }, currentPoint, COLOR_YELLOW);
		}
		break;
	}
}

void Graph::DrawLine(Display& display, v2 a, v2 b, u16 color) const
{
	display.DrawLine(ToPixel(a), ToPixel(b), color);
}

void Graph::DrawFloat(Display& display, v2i pixel, float value, u16 color, u32 digits) const
{
	display.SetCursor(pixel);
	display.SetTextColor(color);
	display.Print(value, digits);
}

v2i Graph::ToPixel(v2 value) const
{
	return {
		position.x + Math::RoundToInt((value.x / maxX) * size.x),
		position.y + Math::RoundToInt((value.y / maxY) * size.y)
	};
}