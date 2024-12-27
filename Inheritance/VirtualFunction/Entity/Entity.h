#pragma once

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void Move(int xAmount, int yAmount);

	virtual const char* GetName() { return "Entity"; }

private:
	int x;
	int y;

};
