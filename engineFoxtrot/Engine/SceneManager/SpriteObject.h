#pragma once



class SpriteObject
{
public:
	API SpriteObject();
	API SpriteObject(const int _textureID, const int _height, const int _width, const int _size, int _animationDelay, const char * _fileName );
	API ~SpriteObject();
	API int getTextureID() const;
	API int  getAmountOfTextures() const;
	API float  getHeight() const;
	API float getWidth() const;
	API const char * getFileName() const;
	API int getLeftPos(uint32_t ticks);

	API int getAnimationDelay();
	API void setAnimationDelay(int speed);
private:
	int animationDelay = 0;
	const int textureID =0;
	const int lengthOfTextures = 0;
	const int height = 0;
	const int width = 0;
	const char * fileName;
};