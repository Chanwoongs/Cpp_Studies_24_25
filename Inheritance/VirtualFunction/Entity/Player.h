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
		// :: ���� ���� ������ (������ �ϸ� Ŭ���� �ȿ��� ã�´�)
		//std::cout << Entity::GetName() << '\n';
		return name; 
	}

private:
	char* name;
};

