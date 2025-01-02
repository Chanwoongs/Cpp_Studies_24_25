#pragma once

#include <iostream>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
class Account
{
public:
	Account();
	Account(int id, const char* name);
	~Account();

	Account(const Account& other)
	{
		this->id = other.id;
		this->nameLength = other.nameLength;
		this->balance = other.balance;

		this->name = new char[this->nameLength + 1];
		strcpy_s(name, this->nameLength + 1, other.name);
	}

	const int GetId() const { return id; }
	const char* GetName() const { return name; }

	void Deposit(int amount);
	void Withdrawal(int amount);

	int CheckBalance();

private:
	int id;
	char* name;
	int nameLength;
	int balance;
};

