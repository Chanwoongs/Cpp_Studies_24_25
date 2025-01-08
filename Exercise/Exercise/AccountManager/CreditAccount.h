#pragma once

#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount() {}
	CreditAccount(int id, const char* name, AccountType type)
		: Account(id, name, type)
	{}
	~CreditAccount() {}

	virtual void Deposit(int amount) override;

	void AddInterest();
};

