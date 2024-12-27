#pragma once

#include "Point.h"

class Circle 
{
public:
	Circle(int x, int y, float r);
	~Circle();
	
public:
	void ShowData();

private:
	Point* p;
	float r;
};

