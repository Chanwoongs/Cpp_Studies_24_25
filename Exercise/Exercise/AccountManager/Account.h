#pragma once

#include <iostream>

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

