#include <iostream>

int main()
{
	// Lambda �Լ� (���� �Լ�)
	// 
	// �����ϸ鼭 ȣ��
	[]() {std::cout << "Hello Lambda.\n";}();

	// ������ ����
	int count = 0;
	auto function = [&count]() -> float // ����� ����
		{
			++count;
			std::cout << "Hello Lambda.\n";
			return 100;
		};
	// ȣ��
	auto returnValue = function();

	function();
	function();
	function();
	function();

	std::cout << "Count: " << count << '\n';
}