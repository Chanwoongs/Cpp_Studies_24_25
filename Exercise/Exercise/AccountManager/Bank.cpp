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
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Credit");
        }
        else if (dynamic_cast<DonationAccount*>(account))
        {
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Donation");
        }
        else
        {
            std::snprintf(buffer, sizeof(buffer), "id: %d, name: %s, balance: %d, type: %s", i, accounts[i]->GetName(), accounts[i]->CheckBalance(), "Normal");
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

            if (strcmp(type, "Credit") == 0)
            {
                CreateAccount(AccountType::Credit, name);
            }
            else if (strcmp(type, "Donation") == 0)
            {
                CreateAccount(AccountType::Donation, name);
            }
            else if (strcmp(type, "Normal") == 0)
            {
                CreateAccount(AccountType::Normal, name);
            }
        }
    }

    fclose(file);
}

void Bank::Save(const char* fileName)
{
    // 저장할 데이터 생성
    char buffer[2048];
    memset(buffer, 0, 2048);

    for (int i = 0; i < id; ++i)
    {
        // 각 계좌별로 문자열 데이터로 직렬화
        const char* data = accounts[i]->Serialize();
        // 데이터 복사
        strcat_s(buffer, data);
        delete data;
    }

    // 파일 저장
    FILE* file = nullptr;
    fopen_s(&file, fileName, "wb");

    if (file)
    {
        fwrite(buffer, strlen(buffer) + 1, 1, file);
        fclose(file);
    }
};

void Bank::Load(const char* fileName)
{
    // 파일 로드
    FILE* file = nullptr;
    fopen_s(&file, fileName, "rb");

    if (file)
    {
        // 파일에서 읽은 데이터를 임시 저장할 버퍼
        char buffer[256];

        while (!feof(file))
        {
            // 한줄 씩 읽기
            fgets(buffer, 256, file);
            
            int id = 0;;
            char name[256];
            int balance = 0;
            char type[256];
            sscanf_s(buffer, "id: %d, name: %[^,], balance: %d, type: %[^\n]\n", &id, name, 256, &balance, type, 256);

            if (strcmp(type, "Credit") == 0)
            {
                CreateAccount(AccountType::Credit, name);
            }
            else if (strcmp(type, "Donation") == 0)
            {
                CreateAccount(AccountType::Donation, name);
            }
            else if (strcmp(type, "Normal") == 0)
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