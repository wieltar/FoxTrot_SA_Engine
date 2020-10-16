#pragma once
#include "IJsonFacade.h"

#if(EXPORT)
class DLLEXPORT JsonFacade: public IJsonFacade
#else
class JsonFacade: public IJsonFacade
#endif
{

};

