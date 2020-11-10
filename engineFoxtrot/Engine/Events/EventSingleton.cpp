#include "stdafx.h"
#include "EventSingleton.h"
// This is the definition (the declaration is in the header).
// Without this, the compiler would not allocate memory for the object.
// This cannot be put inside the header file because of the One-Definition Rule.
EventSingleton EventSingleton::instance;