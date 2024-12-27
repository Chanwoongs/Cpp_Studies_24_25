#pragma once

class IEntity
{
public:
	//Entity();
	//virtual ~Entity();

	//void Move(int xAmount, int yAmount);

	//virtual const char* GetName() { return "Entity"; }
	
	// 순수 가상함수 : 이 함수를 필수적으로 구현하도록 강제함.
	virtual const char* GetName() = 0; // 인터페이스 함수

//	virtual void Test()
//	{
//		//... 
//	}
//
//private:
//	int x;
//	int y;

};
