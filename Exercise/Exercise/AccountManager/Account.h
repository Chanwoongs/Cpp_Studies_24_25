#pragma once

#include <iostream>
#include <unordered_map>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

enum class AccountType
{
	Normal = 0,
	Credit,
	Donation,
	Length
};

class Account
{
public:
	Account();
	Account(int id, const char* name, AccountType type);
	virtual ~Account();

	Account(const Account& other)
	{
		this->id = other.id;
		this->nameLength = other.nameLength;
		this->balance = other.balance;
        this->type = other.type;

		this->name = new char[this->nameLength + 1];
		strcpy_s(name, this->nameLength + 1, other.name);
	}

	const int GetId() const { return id; }
    const char* GetName() const { return name; }
    const AccountType GetType() const { return type; }

	virtual void Deposit(int amount);
	void Withdrawal(int amount);

	int CheckBalance();

protected:
	int id;
	char* name;
	int nameLength;
	int balance;

    AccountType type;
};

