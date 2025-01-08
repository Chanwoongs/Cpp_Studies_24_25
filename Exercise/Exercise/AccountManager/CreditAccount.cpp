#include "CreditAccount.h"

void CreditAccount::Deposit(int amount)
{
    Account::Deposit(amount);

	AddInterest();
}

void CreditAccount::AddInterest()
{
	int interest = (int)balance * 0.01;
	Account::Deposit(interest);
	
	std::cout << "저축한 이자 : " << interest << '\n';
}