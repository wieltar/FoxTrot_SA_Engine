#pragma once
#if(EXPORT)
class DLLEXPORT Message
#else
struct FpsMessage
#endif
{
	FpsMessage(const string& _text, int _r, int _g, int _b)
		: text{ _text }, red{ _r }, green{ _g }, blue{ _b }{}
	const string& text;
	int red, green, blue;
};

#if(EXPORT)
class DLLEXPORT Position
#else
struct TextPosition
#endif
{
	TextPosition(int _x, int _y) : xPos{ _x }, yPos{ _y } {}
	int xPos, yPos;
};

#if(EXPORT)
class DLLEXPORT Size
#else
struct TextSize
#endif
{
	TextSize(int _w, int _h) : width{ _w }, height{ _h } {}
	int width, height;
};