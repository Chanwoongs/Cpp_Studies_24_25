#pragma once

#include <iostream>

#include "Entity.h"
#include "IMoveable.h"

class Player : public IEntity, public IMoveable // 다중 상속. 여러 부모를 가짐.
{
public:
	Player(const char* name);
	~Player() ;

	virtual const char* GetName() override
	{
		// :: 범위 지정 연산자 (생략을 하면 클래스 안에서 찾는다)
		//std::cout << Entity::GetName() << '\n';
		return name; 
	}

	virtual void Move(int x, int y) override
	{

	}

private:
	char* name;
};

