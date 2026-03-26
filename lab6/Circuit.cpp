#include "Circuit.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void Circuit::SetLength(float n)
{
	this->length = n;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	this->cars[this->carNumber] = car;
	this->carNumber++;
}

void Circuit::Race()
{
	//polimorfism
	for (int i = 0; i < carNumber; i++)
	{
		float speed, fuelNeeded;
		speed = cars[i]->GetSpeed(weather);
		fuelNeeded = length * cars[i]->GetFuelConsumption() /100;
		if (fuelNeeded > cars[i]->GetFuelCapacity())
			time[i] = -1;
		else time[i] = length / (speed / 3.6); 
	}
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < carNumber - 1; i++)
		for (int j = i + 1; j < carNumber; j++)
			if (time[i] > time[j])
			{
				swap(time[i], time[j]);
				swap(cars[i], cars[j]);
			}
	printf("Cars that finished the race:\n");
	int k = 0;
	for (int i = 0; i < carNumber; i++)
	{
		if (time[i] != -1)
		{
			printf("- %s in %.2f seconds\n", this->cars[i]->GetName(), time[i]);
			k++;
		}
	}
	if (k == 0) printf("No car finished the race.");
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("\nCars that didn't finish the race:\n");
	int k = 0;
	for (int i = 0; i < this->carNumber; i++)
	{
		if (time[i] == -1)
		{
			printf("- %s\n", this->cars[i]->GetName());
			k++;
		}
	}
	if (k == 0) printf("All cars finished the race.");
}
