#include "stdafx.h"
#include "SpriteObject.h"

using namespace std;

int SpriteObject::getTextureID() const { return textureID; }
int SpriteObject::getAmountOfTextures() const { return lengthOfTextures; }
int SpriteObject::getHeight() const { return height; }
int SpriteObject::getWidth() const { return width; }