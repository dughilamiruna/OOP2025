#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	const char* GetName();
	float GetSpeed(Weather condition);
	float GetFuelCapacity();
	float GetFuelConsumption();
};