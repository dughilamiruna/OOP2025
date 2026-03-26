#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo();
	const char* GetName();
	float GetSpeed(Weather condition);
	float GetFuelCapacity();
	float GetFuelConsumption();
};