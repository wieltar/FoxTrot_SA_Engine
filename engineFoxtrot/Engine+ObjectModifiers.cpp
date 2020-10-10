#include "Engine.h"

/// @brief 
/// @param objId 
/// @param x 
/// @param y 
void Engine::moveObjectTo(const int objId, const int x, const int y)
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
void Engine::moveObjectBy(const int objId, const int withX, const int withY)
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
void Engine::setObjectRotation(const int objId, const int rotation)
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
void Engine::setObjectScale(const int objId, const int scale)
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
void Engine::setObjectDirection(const int objId, const int dir)
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
void Engine::setObjectStatic(const int objId, const bool stat)
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