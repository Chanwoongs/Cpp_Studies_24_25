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
	 
	// 객체 내에서 오버로딩을 하려면 friend를 무조건 붙혀야한다.
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.GetX() << ", " << vector.GetY() << ")\n";
		return os;
	}

	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
};

