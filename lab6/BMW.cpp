#include "BMW.h"
#include <cstring>

BMW::BMW()
{
	fuelCapacity = 55;
	fuelConsumption = 10;
	avgSpeed[0] = 85;
	avgSpeed[1] = 150;
	avgSpeed[2] = 65;
	avgSpeed[3] = 50;

	strcpy_s(name, sizeof(name), "BMW");
}

const char* BMW::GetName()
{
	return name;
}

float BMW::GetSpeed(Weather condition)
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

float BMW::GetFuelCapacity()
{
	return fuelCapacity;
}

float BMW::GetFuelConsumption()
{
	return fuelConsumption;
}