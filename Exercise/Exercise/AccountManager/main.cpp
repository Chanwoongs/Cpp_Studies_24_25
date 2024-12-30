#include <iostream>

#include "Bank.h"
#include "Account.h"

int main()
{
	Bank* bank = new Bank();

	while (true)
	{
		std::cout << "���ϴ� ����� ��ȣ�� �Է��ϼ��� : ";

		int input;
		std::cin >> input;
		std::cin.ignore();

		if (input == 1)
		{
			char name[100];
			std::cout << "�̸��� �Է��ϼ��� : ";
			std::cin.getline(name, 100);
			bank->CreateAccount(name);
		}
		else if (input == 2)
		{
			int id, amount;
			std::cout << "�Ա��Ͻ� ������ ID�� �ݾ��� �Է����ּ��� : ";
			std::cin >> id >> amount;
			bank->Deposit(id, amount);
		}
		else if (input == 3)
		{
			int id, amount;
			std::cout << "����Ͻ� ������ ID�� �ݾ��� �Է����ּ��� : ";
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