#include <iostream>

#include "Bank.h"
#include "Account.h"

int main()
{
	Bank* bank = new Bank();

	while (true)
	{
		std::cout << "원하는 기능의 번호를 입력하세요 : ";

		int input;
		std::cin >> input;
		std::cin.ignore();

		if (input == 1)
		{
			char name[100];
			std::cout << "이름을 입력하세요 : ";
			std::cin.getline(name, 100);
			bank->CreateAccount(name);
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
		else if (input == 'q')
		{
			break;
		}
	}
}