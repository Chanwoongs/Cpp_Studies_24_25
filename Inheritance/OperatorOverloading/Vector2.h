#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2();
	//Vector2(float x = 0.0f, float y = 0.0f); // 기본 생성자와 모호
	Vector2(float x, float y = 0.0f); 
	//Vector2(float x, float y);

	// 더하기
	Vector2 Add(const Vector2& other);

	// 곱하기
	Vector2 Multiply(const Vector2& other);

	// 연산자 오버로딩
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	void operator+=(const Vector2& other);
	 
	// 객체 내에서 오버로딩을 하려면 friend를 무조건 붙혀야한다.
	friend std::ostream& operator<<(std::ostream& os, const Vector2& other)
	{
		os << "(" << other.GetX() << ", " << other.GetY() << ")\n";
		return os;
	}

	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
};

