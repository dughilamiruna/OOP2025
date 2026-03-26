#include "Volvo.h"
#include <cstring>

Volvo::Volvo()
{
	fuelCapacity = 60;
	fuelConsumption = 8;
	avgSpeed[0] = 80;
	avgSpeed[1] = 120;
	avgSpeed[2] = 70;
	avgSpeed[3] = 50;
	strcpy_s(name, sizeof(name), "Volvo");
}

const char* Volvo::GetName()
{
	return name;
}

float Volvo::GetSpeed(Weather condition)
{
	if (condition == Weather::Rain)
		return avgSpeed[0];
	if (condition == Weather::Sunny)
		return avgSpeed[1];
	if (condition == Weather::Snow)
		return avgSpeed[2];
	if (condition == Weather::Fog)
		return avgSpeed[3];
}

float Volvo::GetFuelCapacity()
{
	return fuelCapacity;
}

float Volvo::GetFuelConsumption()
{
	return fuelConsumption;
}