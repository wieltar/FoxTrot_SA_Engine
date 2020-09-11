#pragma once
#include "IJsonFacade.h"
class FileParser
{
public:
	void Load();
	void Save();
private:
	IJsonFacade* jsonFacade;
};

