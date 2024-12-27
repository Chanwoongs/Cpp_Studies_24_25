#include "Circle.h"
#include "iostream"

Circle::Circle(int x, int y, float r)
	: r(r)
{
	p = new Point(x, y);
}

void Circle::ShowData()
{
	std::cout << "�߽� ��ǥ : (" << this->p->GetX() << ", " << this->p->GetY() << ")\n";
	std::cout << "������ : " << this->r << '\n';
	std::cout << "���� ���� : " << this->r * this->r * 3.14 << '\n';
}

Circle::~Circle()
{
	delete p;
}