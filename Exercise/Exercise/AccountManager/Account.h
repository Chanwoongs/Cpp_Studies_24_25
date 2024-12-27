#pragma once
class Account
{
public:
	Account(int id, const char* name);
	~Account();

	void Deposit(int amount);
	void Withdrawal(int amount);

	int CheckBalance();

private:
	int id;
	char* name;
	int nameLength;
	int balance;
};

