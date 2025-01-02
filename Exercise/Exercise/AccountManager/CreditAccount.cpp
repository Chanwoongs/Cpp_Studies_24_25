#include "CreditAccount.h"

void CreditAccount::Deposit(int amount)
{
	this->balance += amount;

	AddInterest();
}

void CreditAccount::AddInterest()
{
	int interest = (int)balance * 0.01;
	this->balance += interest;
	
	std::cout << "저축한 이자 : " << interest << '\n';
}