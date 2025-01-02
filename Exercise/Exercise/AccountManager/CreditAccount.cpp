#include "CreditAccount.h"

void CreditAccount::Deposit(int amount)
{
	this->balance += amount;

	AddInterest();
}

void CreditAccount::AddInterest()
{
	this->balance += (int)balance * 0.01;
}