#include <iostream> // <> 는 지정한 경로만 포함, 경로 설정을 하면 #include <Entity.h>도 가능

#include "Entity.h" // "" 는 현재 폴더들 다 포함
#include "Player.h"

int main()
{
	// Entity 객체 생성
	Entity* entity = new Entity();

	// Player 객체 생성
	Player* player = new Player("Ronnie");

	// 다형성
	Entity* entity2 = player;

	// World -> Level(Scene) == Actor* level[]
	// class TestActor : public Actor
	// 다형성은 stack memory에서 사용이 불가하다. stack은 데이터
	// 포인터로만 가능하다
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor(); AddActor(test);
	// 형변환 실패시 nullptr 반환

	delete entity;
	delete player;
}