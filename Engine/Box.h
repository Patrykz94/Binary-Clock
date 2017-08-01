#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"

class Box
{
public:
	Box() = default;
	Box(Vec2& pos_in);
	void Draw(Vec2& pos_in, Color& c, Graphics& gfx);
	void SetState(bool state);
private:
	Vec2 pos;
	RectF rect;
	static constexpr float size = 100.0f;
	bool onState = false;
};