#include <iostream>

#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <stdlib.h>
#include <crtdbg.h>

#include "Bank.h"
#include "Account.h"

void ClearScreen()
{
	system("cls");
}

int main()
{
	Bank* bank = new Bank();

	while (true)
	{
		std::cout << "원하는 기능의 번호를 입력하세요\n";

		std::cout << "======메뉴======\n";
		std::cout << "1. 계좌 개설\n";
		std::cout << "2. 입금\n";
		std::cout << "3. 출금\n";
		std::cout << "4. 잔액 조회\n";
		std::cout << "5. 프로그램 종료\n";

		int input;
		std::cin >> input;
		std::cin.ignore();

		if (input == 1)
		{
			int accountType;
			std::cout << "계좌 종류를 입력하세요(0. 일반, 1. 이자, 2. 기부) : ";
			std::cin >> accountType;
			std::cin.ignore();
			
			char name[100];
			std::cout << "이름을 입력하세요 : ";
			std::cin.getline(name, 100);
			bank->CreateAccount((AccountType)accountType, name);
		}
		else if (input == 2)
		{
			int id, amount;
			std::cout << "입금하실 계좌의 ID와 금액을 입력해주세요 : ";
			std::cin >> id >> amount;
			bank->Deposit(id, amount);
		}
		else if (input == 3)
		{
			int id, amount;
			std::cout << "출금하실 계좌의 ID와 금액을 입력해주세요 : ";
			std::cin >> id >> amount;
			bank->WithDraw(id, amount);
		}
		else if (input == 4)
		{
			bank->Inquire();
		}
		else if (input == 5)
		{
			break;
		}
		else
		{
			std::cout << "잘못 입력하셨습니다.\n";
		}
	}

	delete bank;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}