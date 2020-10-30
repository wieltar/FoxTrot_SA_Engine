#pragma once


#if(EXPORT)
class DLLEXPORT Object
#else
class SpriteObject
#endif
{
public:
	SpriteObject();
	SpriteObject(const int _textureID, const int _height, const int _width, const int _size, const char * _fileName );
	~SpriteObject();
	int getTextureID() const;
	int getAmountOfTextures() const;
	int getHeight() const;
	int getWidth() const;
	const char * getfileName() const;
	int getLeftPos(uint32_t ticks);
private:
	const int textureID =0;
	const int lengthOfTextures = 0;
	const int height = 0;
	const int width = 0;
	const char * fileName;
};