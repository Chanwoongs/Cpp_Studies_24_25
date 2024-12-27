#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	// 더하기
	Vector2 Add(const Vector2& other);

	// 곱하기
	Vector2 Multiply(const Vector2& other);

	// 연산자 오버로딩
	Vector2 operator+(const Vector2& vector);
	Vector2 operator*(const Vector2& vector);

private:
	float x;
	float y;
};

