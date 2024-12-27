#include "Account.h"
#include <iostream>

Account::Account(int id, const char* name)
    : id(id), balance(0)
{
    nameLength = strlen(name);
    this->name = new char[nameLength + 1];
    strcpy_s(this->name, nameLength + 1, name);
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
}

int Account::CheckBalance()
{
    return this->balance;
}
