
#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include "Platform.h"
#include "Math/v2.h"
#include "Math/v2i.h"
#include "DisplayTypes.h"
#include "Graph.h"
#include "RecordingSet.h"


class Display
{
protected:

	//~ BEGIN Display Settings
	using ScreenType = Adafruit_ST7735;

	// Should X and Y be flipped?
	static constexpr bool bFlippedAxis = false;

	// Offset to apply to screen positions in some displays.
	// Change it as needed by the target screen
	const v2i offset{ 1, 1 };

	ScreenType screen{ 5, 2, 4 }; // CS, RS, RST
	//~ END Display Settings


public:

	Display() {}

	void Start();

	void FillColor(u16 color);

	void DrawPixel(v2i position, u16 color);

	void DrawLine(v2i a, v2i b, u16 color);

	void DrawRect(v2i pos, v2i size, u16 color);

	// BEGIN Prints
	void SetCursor(v2i position)
	{
		position = ToScreen(position);
		screen.setCursor(position.x, position.y);
	}

	v2i GetCursor() const
	{
		return { screen.getCursorX(), screen.getCursorY() };
	}

	void SetTextColor(u16 color)
	{
		screen.setTextColor(color);
	}

	void SetTextColor(u16 color, u16 bg)
	{
		screen.setTextColor(color, bg);
	}

	template<typename StringType>
	void GetTextBounds(StringType string, v2i position, v2i& size)
	{
		i16 posX, posY;
		u16 w, h;
		screen.getTextBounds(string, position.x, position.y, &posX, &posY, &w, &h);
		size = { w, h };
	}

	void SetTextSize(u8 size)
	{
		screen.setTextSize(size);
	}

	void SetRotation(u8 rotation)
	{
		screen.setRotation(rotation);
	}

	template<typename... Args>
	void Print(Args&&... args)
	{
		screen.print(std::forward<Args>(args)...);
	}

	template<typename... Args>
	void PrintLn(Args&&... args)
	{
		screen.println(std::forward<Args>(args)...);
	}

	void Endl()
	{
		screen.println();
	}
	// END Prints

	v2i GetSize() const;

	v2i ToScreen(v2i position) const;
};
