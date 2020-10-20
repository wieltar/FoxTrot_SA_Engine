#pragma once


using namespace std;
#if(EXPORT)
class DLLEXPORT Object
#else
class SpriteObject
#endif
{
public:
	SpriteObject();
	SpriteObject(const int _textureID, const int _size, const int _height, const int _width);
	~SpriteObject();
	int getTextureID() const;
	int getAmountOfTextures() const;
	int getHeight() const;
	int getWidth() const;
private:
	int textureID;
	int lengthOfTextures;
	int height;
	int width;
};