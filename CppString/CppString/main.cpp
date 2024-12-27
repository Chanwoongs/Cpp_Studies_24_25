#include <iostream>
//#include <string>
#include <Array>

void TestFunc(char string[]) // (char* string, int size)
{
	// 함수의 인자로 배열을 넘기면 제대로 동작하지 않을 수 있다.
	// size를 같이 넘기는 게 좋다.
	int count = sizeof(string) / sizeof(string[0]); // 배열 원소 수 Count

	std::cout << "count : " << count << '\n';
}

// 진입점
int main()
{
	// 문자(char -> character)
	char character = 'a';

	// 문자열 (string) 문자 배열
	char charArray[] = "Hello";

	// auto rawString = "Hello";
	const char* rawString = charArray;

	// 배열의 이름은 포인터다.

	// c-library
	int length = 0;
	// 길이 구하기
	while (true)
	{
		// 종료 조건 (탈출 조건)
		// Todo: 종료 조건 없음

		if (rawString[length] == '\0');
		{
			break;
		}

		++length;
	}

	// 함수로 길이 구하기
	size_t len = strlen(rawString); // c-library

	// 힙(Heap) - 자유 메모리 - 책임
	char* heapString = new char[length + 1];

	strcpy_s(heapString, length + 1, rawString);

	// 메모리 복사
	memcpy(heapString, rawString, sizeof(char) * length);
	heapString[length] = '\0';

	std::cout << heapString << std::endl;

	// concaternate, 문자열을 합침
	// 임시 문자열 2개를 잡고 새로운 곳에 할당, 성능면에선 좋지 않음.
	// strcat_s()

	std::cout << charArray[1] << '\n';
	std::cout << *(charArray + 1) << '\n';

	std::cout << sizeof(rawString) << '\n'; // 문자열 크기를 다룰 땐 sizeof로 하면 안된다.

	// 해제
	delete[] heapString;

	TestFunc(charArray);

	std::array<char, 10> testCharArray;

	// 자료구조
	// List(동적 배열, vector), HashTable(검색)

	std::cin.get();
}