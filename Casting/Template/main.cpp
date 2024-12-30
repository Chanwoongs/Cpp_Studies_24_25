#include <iostream>

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	int num1 = 10;
	int num2 = 20;

	Swap(num1, num2);
	std::cout << num1 << " : " << num2 << '\n';

	float num3 = 10.12;
	float num4 = 20.14;

	Swap(num3, num4);
	std::cout << num3 << " : " << num4 << '\n';
}