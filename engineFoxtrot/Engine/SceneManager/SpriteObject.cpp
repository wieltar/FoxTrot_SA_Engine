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