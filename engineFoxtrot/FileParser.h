#pragma once
#include "JsonFacade.h"
class FileParser
{
public:
	void Load();
	void Save();

	// Set to Private after testing!!!
	IJsonFacade* jsonEngine = new JsonFacade;
private:
};

