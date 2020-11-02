#include "stdafx.h"
#include "SpriteObject.h"

SpriteObject::SpriteObject() {}
SpriteObject::SpriteObject(const int _textureID, const float _height, const float _width, const int _size, int _animationDelay, const char* _fileName) :
							textureID(_textureID), height(_height), width(_width), lengthOfTextures(_size), animationDelay(_animationDelay), fileName(_fileName){};
SpriteObject::~SpriteObject() {};

int SpriteObject::getTextureID() const { return textureID; }
int SpriteObject::getAmountOfTextures() const { return lengthOfTextures; }
float SpriteObject::getHeight() const { return height; }
float SpriteObject::getWidth() const { return width; }
const char * SpriteObject::getFileName() const { return fileName; }

int SpriteObject::getAnimationDelay() { return animationDelay; }
void SpriteObject::setAnimationDelay(int delay) { animationDelay = delay; }


/// @brief 
/// A function to give the left position of the sprite
/// @param tick
/// Identifier of the tick of a frame. 
/// @return 
/// a left poition of full texture
float SpriteObject::getLeftPos(uint32_t tick){
	uint32_t pos = tick % lengthOfTextures;
	return pos * width;
}