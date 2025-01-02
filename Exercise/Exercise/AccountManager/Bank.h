#pragma once

#include "Account.h"

class Bank
{
public:
	Bank();
	~Bank();

	Account** GetAccount() const 
	{
		return accounts;
	}

	void Deposit(int id, int amount);
	void WithDraw(int id, int amount);
	void CreateAccount(const char* name);

	void Inquire();

private:
	Account** accounts;

	int id;
};

