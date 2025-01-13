#include "CreditAccount.h"

void CreditAccount::Deposit(int amount)
{
    Account::Deposit(amount);

	AddInterest();
}

const char* CreditAccount::Serialize()
{
    char* buffer = new char[256];

    snprintf(buffer, 256, "id: %d, name: %s , balance: %d, type: %s \n",
        id, name, balance, "Credit");

    return buffer;
}

void CreditAccount::AddInterest()
{
	int interest = (int)balance * 0.01;
	Account::Deposit(interest);
	
	std::cout << "저축한 이자 : " << interest << '\n';
}