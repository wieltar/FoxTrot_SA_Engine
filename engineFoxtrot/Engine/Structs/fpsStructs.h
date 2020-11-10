#pragma once
struct FpsMessage
{
	FpsMessage(const string& _text, uint8_t _r, uint8_t _g, uint8_t _b)
		: text{ _text }, red{ _r }, green{ _g }, blue{ _b }{}
	const string& text;
	uint8_t red, green, blue;
};

struct TextPosition
{
	TextPosition(int _x, int _y) : xPos{ _x }, yPos{ _y } {}
	int xPos, yPos;
};

struct TextSize
{
	TextSize(int _w, int _h) : width{ _w }, height{ _h } {}
	int width, height;
};