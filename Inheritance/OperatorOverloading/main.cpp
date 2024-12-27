#include <iostream>

#include "Vector2.h"

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	//Vector2 result = position.Multiply(speed);

	//Vector2 result = position.operator*(speed);
	Vector2 result = position * speed;

	std::cin.get();
}