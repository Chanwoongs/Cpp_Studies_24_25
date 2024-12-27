#include <iostream>

#include "Vector2.h"

// << ������ �����ε�
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << ", " << vector.GetY() << ")\n";
//	return os;
//}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	//Vector2 result = position.Multiply(speed);

	//Vector2 result = position.operator*(speed);
	Vector2 result = position * speed;

	std::cout << position;
	std::cout << speed;
	std::cout << result;

	std::cin.get();
}