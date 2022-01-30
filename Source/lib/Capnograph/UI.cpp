
#include "UI.h"
#include "Capnograph.h"


void UI::Start()
{
	display.Start();

	graph.position = { 0, 0 };
	const v2i size = display.GetSize();
	graph.size = { size.x, size.y / 2 };
}

void UI::Draw(Capnograph& capnograph)
{
	display.FillColor(COLOR_BLACK);
	graph.Draw(display, capnograph.record);

	//Axis tests
	//display.DrawPixel({0, 0}, COLOR_CYAN);
	//display.DrawPixel({0, 100}, COLOR_MAGENTA);
	//display.DrawPixel({100, 0}, COLOR_RED);

	DrawCurrentValue(capnograph);
	DrawBreathsPerSecond(capnograph);
}

void UI::DrawCurrentValue(Capnograph& capnograph)
{
	const float value = capnograph.sensor.lastValue;

	u16 color = COLOR_WHITE;
	if (value > graph.midYBar)
	{
		color = COLOR_RED;
	}
	else if (value > graph.midYBar * 0.7f)
	{
		color = COLOR_YELLOW;
	}

	display.SetCursor({ 5, display.GetSize().y - 10 });
	display.SetTextSize(4);
	display.SetTextColor(color, COLOR_BLACK);
	display.Print(value, 0);

	display.SetTextSize(1);
	display.Print("kppm");
}

void UI::DrawBreathsPerSecond(Capnograph& capnograph)
{
	const float value = 13.f;

	u16 color = COLOR_WHITE;
	if (value < 4)
	{
		color = COLOR_RED;
	}
	else if (value < 8)
	{
		color = COLOR_YELLOW;
	}

	v2i cursor{
		Math::FloorToI32(display.GetSize().x * 0.75f),
		display.GetSize().y - 10
	};
	display.SetCursor(cursor);
	display.SetTextSize(3);
	display.SetTextColor(color, COLOR_BLACK);
	display.Print(value, 0);

	v2i size;
	display.GetTextBounds("0", cursor, size);

	display.SetCursor(cursor - v2i{ 13, size.y });
	display.SetTextSize(1);
	display.Print("resp/min");
}
