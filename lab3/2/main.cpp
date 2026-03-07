#include "Canvas.h"

int main()
{
	Canvas canvas(20, 20);

    canvas.DrawRect(5, 5, 10, 10, '*');
    canvas.Print();
    canvas.FillRect(5, 5, 10, 10, '*');
    canvas.Print();
    canvas.Clear();

    canvas.DrawLine(1, 5, 10, 15, '*');
    canvas.Print();
    canvas.Clear();

    canvas.DrawCircle(10, 10, 5, '*');
    canvas.Print();
    canvas.FillCircle(10, 10, 5, '*');
    canvas.Print();
    canvas.Clear();
	return 0;
}
