#pragma once

#include "Box.h"

class Clock
{
public:
	Clock();
	void Update(int hou, int min, int sec);
	void Draw(Vec2& pos_in, Graphics& gfx);
	void SetColor(int c);
private:
	std::string toBinary(int n, int len = 0);
	bool toBool(char b);
	std::string h1;
	std::string h2;
	std::string m1;
	std::string m2;
	std::string s1;
	std::string s2;
	Box box[20];
	int colorIndex = 0;
	static constexpr int colNum = 5;
	Color c[colNum] = { { 255, 102, 0 },{ 255, 255, 0 },{ 0, 255, 0 },{ 0, 0, 255 },{ 255, 0, 0 } };
};