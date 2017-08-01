#include "Box.h"

Box::Box(Vec2 & pos_in)
	:
	pos(pos_in),
	rect(pos_in * 50, size, size)
{
}

void Box::Draw(Vec2& pos_in, Graphics & gfx)
{
	if (onState)
	{
		c = Colors::Blue;
	}
	else
	{
		c = Colors::Gray;
	}

	gfx.DrawRect(RectF((pos*size) + pos_in, size, size).GetExpanded(-20.0f), c);
}

void Box::SetState(bool state)
{
	onState = state;
}
