#pragma once

class IEntity
{
public:
	//Entity();
	//virtual ~Entity();

	//void Move(int xAmount, int yAmount);

	//virtual const char* GetName() { return "Entity"; }
	
	// ���� �����Լ� : �� �Լ��� �ʼ������� �����ϵ��� ������.
	virtual const char* GetName() = 0; // �������̽� �Լ�

//	virtual void Test()
//	{
//		//... 
//	}
//
//private:
//	int x;
//	int y;

};
