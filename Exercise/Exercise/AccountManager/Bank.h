#pragma once

#include "Account.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
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

