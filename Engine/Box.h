#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Box
{
public:
	Box() = default;
	Box(Vec2& pos_in);
	void Draw(Vec2& pos_in, Graphics& gfx);
	void SetState(bool state);
private:
	Vec2 pos;
	RectF rect;
	static constexpr float size = 100.0f;
	bool onState = false;
	Color c;
};