#include "stdafx.h"
#include "SpriteObject.h"

SpriteObject::SpriteObject() {}
SpriteObject::SpriteObject(const int _textureID, const int _height, const int _width, const int _size, const char* _fileName) : 
							textureID(_textureID), height(_height), width(_width), lengthOfTextures(_size), fileName(_fileName){};
SpriteObject::~SpriteObject() {};

int SpriteObject::getTextureID() const { return textureID; }
int SpriteObject::getAmountOfTextures() const { return lengthOfTextures; }
int SpriteObject::getHeight() const { return height; }
int SpriteObject::getWidth() const { return width; }
const char * SpriteObject::getfileName() const { return fileName; }


/// @brief 
/// A function to give the left position of the sprite
/// @param tick
/// Identifier of the tick of a frame. 
/// @return 
/// a left poition of full texture
int SpriteObject::getLeftPos(uint32_t tick){
	uint32_t pos = tick % lengthOfTextures;
	return pos * width;
}