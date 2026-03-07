#include "Canvas.h"
#include <cstdio>
#include <cmath>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	matrix = new char* [width];
	for (int i = 0; i < width; i++)
	{
		matrix[i] = new char[height];
		for (int j = 0; j < height; j++)
			matrix[i][j] = 32;
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int x0 = ray;
	int y0 = 0;
	int err = 0;

	while (x0 >= y0) {
		SetPoint(x + x0, y + y0, ch);
		SetPoint(x + y0, y + x0, ch);
		SetPoint(x - y0, y + x0, ch);
		SetPoint(x - x0, y + y0, ch);
		SetPoint(x - x0, y - y0, ch);
		SetPoint(x - y0, y - x0, ch);
		SetPoint(x + y0, y - x0, ch);
		SetPoint(x + x0, y - y0, ch);

		if (err <= 0) {
			y0 += 1;
			err += 2 * y0 + 1;
		}
		if (err > 0) {
			x0 -= 1;
			err -= 2 * x0 + 1;
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = y - ray; i <= y + ray; i++) 
		for (int j = x - ray; j <= x + ray; j++)
			if ((j - x) * (j - x) + (i - y) * (i - y) <= ray * ray)
				SetPoint(j, i, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, bottom, left, top, ch);  //latura sus
	DrawLine(right, bottom, right, top, ch); //latura jos
	DrawLine(left, bottom, right, bottom, ch); //stanga 
	DrawLine(left, top, right, top, ch); //dreapta
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int x = top; x <= bottom; x++) 
		for (int y = left; y <= right; y++)
			SetPoint(x, y, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	//dist pe cele doua axe
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);

	int sx, sy;
	//directia
	if (x1 < x2) sx = 1;
	else sx = -1;
	if (y1 < y2) sy = 1;
	else sy = -1;

	//eroarea(err)
	int err = dx + dy; int err2;
	
	//parcurgerea 
	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;

		err2 = 2 * err;

		//pas spre axa X
		if (err2 >= dy)
		{
			err = err + dy;
			x1 = x1 + sx;
		}
		//pas spre axa Y
		if (err2 <= dx)
		{
			err = err + dx;
			y1 = y1 + sy;
		}
	}

}

void Canvas::Print()
{
	for (int i = 0; i < height ; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; ++i) 
		for (int j = 0; j < height; ++j) 
			matrix[i][j] = 32;
}
