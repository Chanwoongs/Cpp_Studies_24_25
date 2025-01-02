#include <iostream>
#include <fstream>

int main()
{
	// 파일 열기
	FILE* file = nullptr;

	// 파일 열기
	fopen_s(&file, "Test.txt", "rt");

	// 예외 처리
	if (file != nullptr)
	{
		// 임의 접근 (Random Access)
		fseek(file, 24, SEEK_SET);

		// 버퍼
		char buffer[256];

		// 데이터 읽기
		while (!feof(file))
		{
			fgets(buffer, 256, file);

			std::cout << buffer;
		}

		// 파일 닫기
		fclose(file);
	}

	// 테스트 문자열
	const char* stringValue = "id : 10 name : chanwoong balance : 1000000";

	// C 스타일
	// 문자열에서 특정 값 가져오기
	int id = 0;
	char name[256];
	int balance = 0;

	sscanf_s(stringValue, "id : %d name : %s balance : %d", &id, name, 256, &balance);

	std::cout << "id : " << id << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "balance : " << balance << '\n';

	// 데이터 쓰기
	int id_ = 10;
	const char* name_ = "chanwoong";
	int balance_ = 1000000;

	// 문자열 변환
	// 저장할 버퍼
	char data[1024] = { };
	snprintf(data, 1024, "id : %d name : %s balance : %d", id_, name_, balance_);

	// 테스트 출력
	std::cout << data << '\n';

	// 파일로 생성
	FILE* file_ = nullptr;
	fopen_s(&file_, "AccountData.txt", "wt");
	size_t length = strlen(data);
	if (file_ != nullptr)
	{
		fwrite(data, length, 1, file_);
		fclose(file_);
	}

	// 파일 읽기
	FILE* _file = nullptr;
	fopen_s(&_file, "AccountData.txt", "rt");
	if (file != nullptr)
	{
		char total[2048] = { };
		char buffer[1024];

		while (!feof(_file))
		{
			fgets(buffer, 1024, _file);

			//std::cout << buffer;

			// 문자열 합치기
			strcat_s(total, buffer);
		}
		std::cout << total;
		fclose(_file);

		// 값 가져오기
		int id1 = 0;
		char nameBuffer[256] = { };
		int balance1 = 0;

		sscanf_s(total, "id : %d, name : %s balance : %d", &id1, nameBuffer, 256, &balance1);	

		std::cin.get();
	}
}