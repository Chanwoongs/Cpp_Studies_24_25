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

		std::cout << id << "번 계좌에 " << amount << "원 입금했습니다.\n";
	}
	else
	{
		std::cout << "계좌를 찾을 수 없습니다.\n";
	}
}

void Bank::WithDraw(int id, int amount)
{
	if (this->accounts[id]->GetId() != -1)
	{
		this->accounts[id]->Withdrawal(amount);

		std::cout << id << "번 계좌에서 " << amount << "원 출금했습니다. 잔액 : " << this->accounts[id]->CheckBalance() << '\n';
	}
	else
	{
		std::cout << "계좌를 찾을 수 없습니다.\n";
	}
}

void Bank::CreateAccount(AccountType accountType, const char* name)
{
	Account* account = nullptr;

	switch (accountType)
	{
	case AccountType::Normal:
		account = new Account(id, name, AccountType::Normal);
		break;
	case AccountType::Credit:
		account = new CreditAccount(id, name, AccountType::Credit);
		break;
	case AccountType::Donation:
		account = new DonationAccount(id, name, AccountType::Donation);
		break;
	default:
		break;
	}
	this->accounts[id] = account;

    if (this->accounts[id] != nullptr)
    {
        std::cout << this->accounts[id]->GetName() << " 고객님의 " << id << "번 계좌가 생성되었습니다\n";
        id++;
    }
}

void Bank::SaveData()
{
    FILE* file = nullptr;
    fopen_s(&file, "data.txt", "wt");

    if (file == nullptr)
    {
        std::cout << "파일을 열 수 없어 저장이 불가능합니다.\n";
        return;
    }

    for (int i = 0; i < id; ++i)
    {
        Account* account = accounts[i];
        char buffer[256] = {' '};

        if (dynamic_cast<CreditAccount*>(account))
        {
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Credit Account");
        }
        else if (dynamic_cast<DonationAccount*>(account))
        {
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Donation Account");
        }
        else
        {
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Normal Account");
        }
        fwrite(buffer, 1, sizeof(buffer), file);
    }

    fclose(file);
}

void Bank::LoadData()
{
    FILE* file = nullptr;
    fopen_s(&file, "data.txt", "rt");

    if (file == nullptr)
    {
        std::cout << "파일을 열 수 없어 데이터를 불러올 수 없습니다.\n";
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        buffer[strcspn(buffer, "\r\n")] = '\0';

        int id = 0;
        char name[50];
        int balance = 0;
        char type[50];

        if (sscanf_s(buffer, "id: %d, name: %s, balance: %d, type: %s", &id, name, 50, &balance, type, 50))
        {
            std::cout << id << ' ' << name << ' ' << balance << ' ' << type << '\n';

            if (strcmp(type, "Credit Account") == 0)
            {
                CreateAccount(AccountType::Credit, name);
            }
            else if (strcmp(type, "Donation Account") == 0)
            {
                CreateAccount(AccountType::Donation, name);
            }
            else if (strcmp(type, "Normal Account") == 0)
            {
                CreateAccount(AccountType::Normal, name);
            }
        }
    }

    fclose(file);
}

void Bank::Inquire()
{
	for (int i = 0; i < id; i++)
	{
        if (this->accounts[i] == nullptr)
        {
            continue;
        }

        if (dynamic_cast<CreditAccount*>(this->accounts[i]))
        {
            std::cout << this->accounts[i]->GetName() << " 고객님의 이자 계좌 잔액 : " << this->accounts[i]->CheckBalance() << '\n';
        }
        else if (dynamic_cast<DonationAccount*>(this->accounts[i]))
        {
            std::cout << this->accounts[i]->GetName() << " 고객님의 기부 계좌 잔액 : " << this->accounts[i]->CheckBalance() << '\n';
        }
        else
        {
            std::cout << this->accounts[i]->GetName() << " 고객님의 일반 계좌 잔액 : " << this->accounts[i]->CheckBalance() << '\n';
        }
	}
}