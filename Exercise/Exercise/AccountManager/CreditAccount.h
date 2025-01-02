#pragma once

#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount() {}
	CreditAccount(int id, const char* name)
		: Account(id, name)
	{}
	~CreditAccount() {}

	virtual void Deposit(int amount) override;

	void AddInterest();
};

