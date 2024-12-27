#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	// ���ϱ�
	Vector2 Add(const Vector2& other);

	// ���ϱ�
	Vector2 Multiply(const Vector2& other);

	// ������ �����ε�
	Vector2 operator+(const Vector2& vector);
	Vector2 operator*(const Vector2& vector);

private:
	float x;
	float y;
};

