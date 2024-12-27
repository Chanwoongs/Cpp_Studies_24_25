#pragma once
class Point
{
public:
	Point(int x, int y);
	~Point();

	int GetX() const { return x; }
	void SetX(int x) { this->x = x; }
	int GetY() const { return y; }
	void SetY(int y) { this->y = y; }
	
private:
	int x;
	int y;
};

