#include "Bank.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

Bank::Bank()
{
	this->id = 0;

	accounts = new Account*[100];

	for (int i = 0; i < 100; i++)
	{
		accounts[i] = nullptr;
	}
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

void Bank::CreateAccount(AccountType accountType, const char* name)
{
	Account* account = nullptr;

	switch (accountType)
	{
	case AccountType::Normal:
		account = new Account(id, name);
		break;
	case AccountType::Credit:
		account = new CreditAccount(id, name);
		break;
	case AccountType::Donation:
		account = new DonationAccount(id, name);
		break;
	default:
		break;
	}
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
