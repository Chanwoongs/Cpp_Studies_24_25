#pragma once

#include <iostream>

#include "Entity.h"
#include "IMoveable.h"

class Player : public IEntity, public IMoveable // ���� ���. ���� �θ� ����.
{
public:
	Player(const char* name);
	~Player() ;

	virtual const char* GetName() override
	{
		// :: ���� ���� ������ (������ �ϸ� Ŭ���� �ȿ��� ã�´�)
		//std::cout << Entity::GetName() << '\n';
		return name; 
	}

	virtual void Move(int x, int y) override
	{

	}

private:
	char* name;
};

