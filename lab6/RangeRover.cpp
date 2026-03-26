#include "RangeRover.h"
#include <cstring>

RangeRover::RangeRover()
{
	fuelCapacity = 80;
	fuelConsumption = 12;
	avgSpeed[0] = 100;
	avgSpeed[1] = 140;
	avgSpeed[2] = 75;
	avgSpeed[3] = 50;

	strcpy_s(name, sizeof(name), "RangeRover");
}

const char* RangeRover::GetName()
{
	return name;
}

float RangeRover::GetSpeed(Weather condition)
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

float RangeRover::GetFuelCapacity()
{
	return fuelCapacity;
}

float RangeRover::GetFuelConsumption()
{
	return fuelConsumption;
}