#pragma once
struct Message {
	Message(const string& _text, int _r, int _g, int _b)
		: text{ _text }, red{ _r }, green{ _g }, blue{ _b }{}
	const string& text;
	int red, green, blue;
};

struct Position {
	Position(int _x, int _y) : xPos{ _x }, yPos{ _y } {}
	int xPos, yPos;
};

struct Size {
	Size(int _w, int _h) : width{ _w }, height{ _h } {}
	int width, height;
};