#pragma once

#include <iostream>

#include "Entity.h"

class Player : public Entity
{
public:
	Player(const char* name);
	~Player();

	virtual const char* GetName() override
	{
		// :: 범위 지정 연산자 (생략을 하면 클래스 안에서 찾는다)
		//std::cout << Entity::GetName() << '\n';
		return name; 
	}

private:
	char* name;
};

