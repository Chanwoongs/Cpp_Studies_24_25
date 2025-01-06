#include <iostream>

// 스마트 포인터 사용을 위한 헤더
#include <memory>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Resources
{
public:
	Resources()
	{
		std::cout << "생성자 호출\n";
	}

	~Resources()
	{
		std::cout << "소멸자 호출\n";
	}

	void Use()
	{
		std::cout << "자원 사용\n";
	}

private:

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::unique_ptr<Resources> resources = std::make_unique<Resources>();
	resources->Use();
	//std::unique_ptr<Resources> resources2 = resources;
	std::unique_ptr<Resources> resources2 = std::move(resources);

	// Move한 뒤 기존 포인터 사용하면 안된다.
	resources->Use();
	resources2->Use();

	Resources* re = new Resources();

	// Raw 포인터 Get, delete하면 안된다.
	Resources* rawPointer = resources.get();
	rawPointer->Use();

	//delete rawPointer;

	{
		std::unique_ptr<Resources> resources3 = std::make_unique<Resources>();
		resources3->Use();
	}
	std::cout << "끝\n";

	Resources& refResource = *resources2;
	refResource.Use();
}