#pragma once

#include "Account.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
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
	void CreateAccount(AccountType accountType, const char* name);

    void SaveData();
	void LoadData();

    void Save(const char* fileName);
    void Load(const char* fileName);

	void Inquire();

private:
	Account** accounts;

	int id;
};

