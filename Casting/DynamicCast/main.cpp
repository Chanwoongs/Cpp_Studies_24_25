#include <iostream>

class Actor
{
public:
	virtual void Print()
	{
		std::cout << "Value : " << a << '\n';
	}

public:
	int a;
};

class Player : public Actor
{

};

int main()
{
	// 객체 생성
	Actor* actor = new Actor();
	Player* player = new Player();

	// 업 캐스팅
	Actor* actorPoint = player;
	//Actor* actorPoint = reinterpret_cast<Actor*>(player);

	// 객체의 vtable이 없으면 에러
	//Player* playerPointer = dynamic_cast<Player*>(actorPoint);

	// ok
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok
	Player* player2 = static_cast<Player*>(actor);

	// 문제가 나야하는데 나지 않음 (위험)
	std::cout << player2->a << '\n';

	Player* player3 = dynamic_cast<Player*>(actor);
	// player3에 null값이 들어간다 (정상)
	// 항상 예외 처리
	if (player3)
	{
		player3->Print();
	}
	else
	{
		std::cout << "형변환 실패\n";
	}

	// if 문 안에 넣기
	if (Player* player4 = dynamic_cast<Player*>(actor))
	{
		player4->Print();
	}
	else
	{
		std::cout << "형변환 실패\n";
	}
}