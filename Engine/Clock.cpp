#include "Clock.h"

Clock::Clock()
{
	for (int i = 0; i < 20; i++)
	{
		if (i < 2)
		{
			box[i] = Vec2(0.0f, float(-i));
		}
		else if (i < 6)
		{
			box[i] = Vec2(1.0f, float(-i + 2));
		}
		else if (i < 9)
		{
			box[i] = Vec2(2.0f, float(-i + 6));
		}
		else if (i < 13)
		{
			box[i] = Vec2(3.0f, float(-i + 9));
		}
		else if (i < 16)
		{
			box[i] = Vec2(4.0f, float(-i + 13));
		}
		else if (i < 20)
		{
			box[i] = Vec2(5.0f, float(-i + 16));
		}
	}
}

void Clock::Update(int hou_in, int min_in, int sec_in)
{
	h1 = toBinary(hou_in / 10 % 10, 2);
	h2 = toBinary(hou_in % 10, 4);

	m1 = toBinary(min_in / 10 % 10, 3);
	m2 = toBinary(min_in % 10, 4);

	s1 = toBinary(sec_in / 10 % 10, 3);
	s2 = toBinary(sec_in % 10, 4);
	
	for (int i = 0; i < 20; i++)
	{
		if (i < 2)
		{
			box[i].SetState(toBool(h1.at((h1.length()-1) - i)));
		}
		else if (i < 6)
		{
			
			box[i].SetState(toBool(h2.at((h2.length() - 1) - (i - 2))));
		}
		else if (i < 9)
		{
			box[i].SetState(toBool(m1.at((m1.length() - 1) - (i - 6))));
		}
		else if (i < 13)
		{
			box[i].SetState(toBool(m2.at((m2.length() - 1) - (i - 9))));
		}
		else if (i < 16)
		{
			box[i].SetState(toBool(s1.at((s1.length() - 1) - (i - 13))));
		}
		else if (i < 20)
		{
			box[i].SetState(toBool(s2.at((s2.length() - 1) - (i - 16))));
		}
	}
}

void Clock::Draw(Vec2& pos_in, Graphics & gfx)
{
	for (int i = 0; i < 20; i++)
	{
		box[i].Draw(pos_in, c[colorIndex], gfx);
	}
}

void Clock::SetColor(int i)
{
	auto mod = [](int val, int mod) { return (val%mod + mod) % mod; };

	colorIndex = mod(colorIndex+i, colNum);
}

std::string Clock::toBinary(int n, int len)
{
	std::string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	while (r.length() < len) { r = "0" + r; }
	return r;
}

bool Clock::toBool(char b)
{
	return b == '1';
}
