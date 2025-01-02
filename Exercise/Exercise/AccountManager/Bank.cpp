#include "Bank.h"

Bank::Bank()
{
	this->id = 0;

	accounts = new Account*[100];
}

Bank::~Bank()
{
	for (int i = 0; i < 100; i++)
	{
		delete accounts[i];
	}
	delete[] this->accounts;
}

void Bank::Deposit(int id, int amount)
{
	if (this->accounts[id]->GetId() != -1)
	{
		this->accounts[id]->Deposit(amount);

		std::cout << id << "�� ���¿� " << amount << "�� �Ա��߽��ϴ�.\n";
	}
	else
	{
		std::cout << "���¸� ã�� �� �����ϴ�.\n";
	}
}

void Bank::WithDraw(int id, int amount)
{
	if (this->accounts[id]->GetId() != -1)
	{
		this->accounts[id]->Withdrawal(amount);

		std::cout << id << "�� ���¿��� " << amount << "�� ����߽��ϴ�. �ܾ� : " << this->accounts[id]->CheckBalance() << '\n';
	}
	else
	{
		std::cout << "���¸� ã�� �� �����ϴ�.\n";
	}
}

void Bank::CreateAccount(const char* name)
{
	Account* account = new Account(id, name);
	this->accounts[id] = account;

	std::cout << this->accounts[id]->GetName() << " ������ " << id << "�� ���°� �����Ǿ����ϴ�\n";
	id++;
}

void Bank::Inquire()
{
	for (int i = 0; i < id; i++)
	{
		std::cout << this->accounts[i]->GetName() << " ������ �ܾ� : " << this->accounts[i]->CheckBalance() << '\n';
	}
}
