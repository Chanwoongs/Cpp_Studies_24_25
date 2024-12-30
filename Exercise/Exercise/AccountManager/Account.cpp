#include "Account.h"
#include <iostream>

Account::Account()
    : id(-1), nameLength(-1), name(nullptr), balance(0)
{
}

Account::Account(int id, const char* name)
    : id(id), balance(0)
{
    this->nameLength = strlen(name);
    this->name = new char[this->nameLength + 1];
    strcpy_s(this->name, this->nameLength + 1, name);
}

Account::~Account()
{
    delete[] name;
}

void Account::Deposit(int amount)
{
    this->balance += amount;
}

void Account::Withdrawal(int amount)
{
    this->balance -= amount;
    if (this->balance <= 0) this->balance = 0;
}

int Account::CheckBalance()
{
    return this->balance;
}
