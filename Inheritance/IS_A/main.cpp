#include <iostream>

#include "Point.h"
#include "Circle.h"

int main()
{
	Circle* circle = new Circle(3, 5, 2.5f);
	circle->ShowData();
	delete circle;
}