#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	const char* GetName();
	float GetSpeed(Weather condition);
	float GetFuelCapacity();
	float GetFuelConsumption();
};