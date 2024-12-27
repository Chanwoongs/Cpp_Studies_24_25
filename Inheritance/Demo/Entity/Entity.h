#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	void Move(int xAmount, int yAmount);

private:
	int x;
	int y;

};
