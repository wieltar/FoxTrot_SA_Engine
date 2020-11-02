#pragma once


#if(EXPORT)
class DLLEXPORT Object
#else
class SpriteObject
#endif
{
public:
	SpriteObject();
	SpriteObject(const int _textureID, const int _height, const int _width, const int _size, int _animationDelay, const char * _fileName );
	~SpriteObject();
	int getTextureID() const;
	int  getAmountOfTextures() const;
	float  getHeight() const;
	float getWidth() const;
	const char * getFileName() const;
	int getLeftPos(uint32_t ticks);

	int getAnimationDelay();
	void setAnimationDelay(int speed);
private:
	int animationDelay = 0;
	const int textureID =0;
	const int lengthOfTextures = 0;
	const int height = 0;
	const int width = 0;
	const char * fileName;
};