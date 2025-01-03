#include <iostream>
#include <functional> // C++ 11

// 함수 포인터
typedef void (*functionPointer)();
void(*functionPointer)();
using FP = void(*)();

std::function<void()> newFunctionPointer;

int main()
{
	// Lambda 함수 (무명 함수)
	// 
	// 선언하면서 호출
	[]() {std::cout << "Hello Lambda.\n";}();

	// 변수에 저장
	int count = 0;
	auto function = [&count]() -> float // 명시적 선언
		{
			++count;
			std::cout << "Hello Lambda.\n";
			return 100;
		};
	// 호출
	auto returnValue = function();

	functionPointer = []() {std::cout << "Hello" << '\n';};
	functionPointer();

	newFunctionPointer = functionPointer;

	function();
	function();
	function();
	function();

	newFunctionPointer();

	std::cout << "Count: " << count << '\n';
}