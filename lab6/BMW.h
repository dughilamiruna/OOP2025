#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	const char* GetName();
	float GetSpeed(Weather condition);
	float GetFuelCapacity();
	float GetFuelConsumption();
};