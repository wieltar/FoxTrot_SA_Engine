#pragma once
#include "JsonFacade.h"

#if(EXPORT)
class DLLEXPORT FileParser
#else
class FileParser
#endif
{
public:
	void Load();
	void Save();

	// Set to Private after testing!!!
	IJsonFacade* jsonEngine = new JsonFacade;
private:
};

