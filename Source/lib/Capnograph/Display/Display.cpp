
#include "Display/Display.h"


void Display::Start()
{
	screen.enableTearing(false);
	screen.initR(INITR_BLACKTAB);
	FillColor(COLOR_BLACK);
	SetRotation(1);
}

void Display::FillColor(u16 color)
{
	screen.fillScreen(color);
}

void Display::DrawPixel(v2i position, u16 color)
{
	position = ToScreen(position);
	screen.drawPixel(position.x, position.y, color);
}

void Display::DrawLine(v2i a, v2i b, u16 color)
{
	a = ToScreen(a);
	b = ToScreen(b);
	screen.drawLine(a.x, a.y, b.x, b.y, color);
}

void Display::DrawRect(v2i pos, v2i size, u16 color)
{
	pos = ToScreen(pos);
	size = ToScreen(size);
	screen.drawRect(pos.x, pos.y, size.x, size.y, color);
}

v2i Display::GetSize() const
{
	return {
		i32(screen.width()) - offset.x,
		i32(screen.height()) - offset.y
	};
}

v2i Display::ToScreen(v2i position) const
{
	position += offset;
	position.y = GetSize().y - position.y;
	if (bFlippedAxis) // constexpr
	{
		return { position.y, position.x }; // Flip screen
	}
	else
	{
		return position;
	}
}
