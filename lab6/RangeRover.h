#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	const char* GetName();
	float GetSpeed(Weather condition);
	float GetFuelCapacity();
	float GetFuelConsumption();
};