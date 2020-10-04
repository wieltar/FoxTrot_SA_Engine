#include "Engine.h"

/// @brief 
/// @param objId 
/// @param x 
/// @param y 
void Engine::moveObjectTo(int objId, int x, int y)
{
	try
	{
		sceneManager.moveObject(objId, x, y);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param objId 
/// @param withX 
/// @param withY 
void Engine::moveObjectBy(int objId, int withX, int withY)
{
	try
	{
		sceneManager.moveObjectRelative(objId, withX, withY);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param objId 
/// @param rotation 
void Engine::setObjectRotation(int objId, int rotation)
{
	try
	{
		sceneManager.rotateObject(objId, rotation);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param objId 
/// @param scale 
void Engine::setObjectScale(int objId, int scale)
{
	try
	{
		sceneManager.setObjectScale(objId, scale);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param objId 
/// @param dir 
void Engine::setObjectDirection(int objId, int dir)
{
	try
	{
		sceneManager.setObjectDirection(objId, dir);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}

/// @brief 
/// @param objId 
/// @param stat 
void Engine::setObjectStatic(int objId, bool stat)
{
	try
	{
		sceneManager.setObjectStatic(objId, stat);
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << ERRORCODES[e] << '\n';
	}
}