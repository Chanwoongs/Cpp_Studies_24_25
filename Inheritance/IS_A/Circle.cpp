#include "Circle.h"
#include "iostream"

Circle::Circle(int x, int y, float r)
	: r(r)
{
	p = new Point(x, y);
}

void Circle::ShowData()
{
	std::cout << "중심 좌표 : (" << this->p->GetX() << ", " << this->p->GetY() << ")\n";
	std::cout << "반지름 : " << this->r << '\n';
	std::cout << "원의 넓이 : " << this->r * this->r * 3.14 << '\n';
}

Circle::~Circle()
{
	delete p;
}