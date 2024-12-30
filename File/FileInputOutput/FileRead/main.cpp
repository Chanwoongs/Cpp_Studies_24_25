#include <iostream>

int main()
{
	char buffer[256];
	FILE* file = nullptr;

	fopen_s(&file, "Test.txt", "rt");

	if (file != nullptr)
	{
		// 버퍼에 내용 읽어들이기
		while (true)
		{
			//if (fgets(buffer, 256, file) == nullptr)
			if (fgets(buffer, 10, file) == nullptr)
			{
				break;
			}
			std::cout << buffer;
		}

		fclose(file);
	}

	FILE* file2 = nullptr;

	fopen_s(&file2, "Test.txt", "rt");

	// feof 사용 좀 더 일반적
	if (file2 != nullptr)
	{
		// 버퍼에 내용 읽어들이기
		while (!feof(file2))
		{
			fgets(buffer, 10, file2);

			std::cout << buffer;
		}

		fclose(file2);
	}
}