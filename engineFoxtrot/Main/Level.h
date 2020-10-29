#pragma once
#include "SceneManager/Scene.h"

/// @brief 
/// Level class. Level has all the information. 

#if(EXPORT)
class DLLEXPORT Object
#else
class Level : Scene
#endif
{
public:
	virtual void OnAtach() override;
	virtual void Start() override;
	virtual void OnDetach() override;
private:

};