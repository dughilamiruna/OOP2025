#include "Fiat.h"
#include <cstring>

Fiat::Fiat()
{
	fuelCapacity = 55;
	fuelConsumption = 10;
	avgSpeed[0] = 85;
	avgSpeed[1] = 150;
	avgSpeed[2] = 65;
	avgSpeed[3] = 50;

	strcpy_s(name, sizeof(name), "Fiat");
}

const char* Fiat::GetName()
{
	return name;
}

float Fiat::GetSpeed(Weather condition)
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

float Fiat::GetFuelCapacity()
{
	return fuelCapacity;
}

float Fiat::GetFuelConsumption()
{
	return fuelConsumption;
}