#include <iostream> // <> �� ������ ��θ� ����, ��� ������ �ϸ� #include <Entity.h>�� ����

#include "Entity.h" // "" �� ���� ������ �� ����
#include "Player.h"

int main()
{
	// Entity ��ü ����
	Entity* entity = new Entity();

	// Player ��ü ����
	Player* player = new Player("Ronnie");

	// ������
	Entity* entity2 = player;

	// World -> Level(Scene) == Actor* level[]
	// class TestActor : public Actor
	// �������� stack memory���� ����� �Ұ��ϴ�. stack�� ������
	// �����ͷθ� �����ϴ�
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor(); AddActor(test);
	// ����ȯ ���н� nullptr ��ȯ

	delete entity;
	delete player;
}