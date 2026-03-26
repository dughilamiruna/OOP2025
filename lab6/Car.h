#pragma once
#include "Weather.h"

class Car
{
protected:
	char name[20];
	float fuelCapacity; 
	float fuelConsumption;
	int avgSpeed[4];

public:
	virtual ~Car() {};
	virtual const char* GetName() = 0;
	virtual float GetSpeed(Weather condition) = 0;
	virtual float GetFuelCapacity() = 0;
	virtual float GetFuelConsumption() = 0;
};