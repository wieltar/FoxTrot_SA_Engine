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
private:
	int textureID;
	int lengthOfTextures;
	int height;
	int width;
	const char * fileName;
};