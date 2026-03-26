#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	float length;
	Weather weather;
	int carNumber = 0;
	Car* cars[17];
	float time[10];
public:
	void SetLength(float n);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};