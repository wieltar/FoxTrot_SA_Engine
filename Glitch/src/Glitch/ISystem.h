#pragma once
class ISystem
{
public:
	virtual void OnUpdate() = 0;
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
};