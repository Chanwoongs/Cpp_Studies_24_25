#include <iostream>

// 스마트 포인터 사용을 위한 헤더
#include <memory>

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
	std::shared_ptr<Resources> resource1 = std::make_shared<Resources>();
	std::shared_ptr<Resources> resource2 = resource1;

	std::cout << "사용 횟수 : " << resource1.use_count() << '\n';

	resource2 = nullptr;
	std::cout << "사용 횟수 : " << resource1.use_count() << '\n';
}