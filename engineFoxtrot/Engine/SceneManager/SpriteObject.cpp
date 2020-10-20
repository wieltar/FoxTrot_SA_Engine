#include "stdafx.h"
#include "SpriteObject.h"

using namespace std;
SpriteObject::SpriteObject() {}
SpriteObject::SpriteObject(const int _textureID, const int _height, const int _width, const int _size) : textureID(_textureID), height(_height), width(_width), lengthOfTextures(_size) {};
SpriteObject::~SpriteObject() {};

int SpriteObject::getTextureID() const { return textureID; }
int SpriteObject::getAmountOfTextures() const { return lengthOfTextures; }
int SpriteObject::getHeight() const { return height; }
int SpriteObject::getWidth() const { return width; }