#include "Box.h"
#include "Clock.h"

Box::Box(Vec2 & pos_in)
	:
	pos(pos_in),
	rect(pos_in * 50, size, size)
{
}

void Box::Draw(Vec2& pos_in, Color& c, Graphics & gfx)
{
	Color col;
	if (onState)
	{
		col = c;
	}
	else
	{
		col = Colors::MakeRGB(50, 50, 50);
	}

	gfx.DrawRect(RectF((pos*size) + pos_in, size, size).GetExpanded(-20.0f), col);
}

void Box::SetState(bool state)
{
	onState = state;
}
