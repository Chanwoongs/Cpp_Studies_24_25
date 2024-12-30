#include <iostream>

// class template
template<typename T>
class Data
{
public:
	Data(T newData)
		: data(newData)
	{

	}

	void SetData(T newData)
	{
		data = newData;
	}

	T GetData() const { return data; }

private:
	T data;
};

int main()
{
	Data<int> data1(10);
	std::cout << data1.GetData() << '\n';

	Data<float> data2(234.5f);
	std::cout << data2.GetData() << '\n';
}