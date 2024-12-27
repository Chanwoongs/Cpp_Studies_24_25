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
	 
	// ��ü ������ �����ε��� �Ϸ��� friend�� ������ �������Ѵ�.
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

