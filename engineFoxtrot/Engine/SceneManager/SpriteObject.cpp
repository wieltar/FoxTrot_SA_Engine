#include "stdafx.h"
#include "SpriteObject.h"

using namespace std;
SpriteObject::SpriteObject() {}
SpriteObject::SpriteObject(const int _textureID, const int _size, const int _height, const int _width) : textureID(_textureID), lengthOfTextures(_size), height(_height), width(_width) {};
SpriteObject::~SpriteObject() {};

int SpriteObject::getTextureID() const { return textureID; }
int SpriteObject::getAmountOfTextures() const { return lengthOfTextures; }
int SpriteObject::getHeight() const { return height; }
int SpriteObject::getWidth() const { return width; }