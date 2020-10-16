#pragma once
#include "JsonFacade.h"

#if(EXPORT)
class DLLEXPORT FileParser
#else
class FileParser
#endif
{
public:

	// Set to Private after testing!!!
	IJsonFacade* jsonEngine = new JsonFacade;
private:
};

