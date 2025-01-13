#include "Account.h"
#include <iostream>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

Account::Account()
    : id(-1), nameLength(-1), name(nullptr), balance(0), type(type)
{
}

Account::Account(int id, const char* name, AccountType type)
    : id(id), balance(0), type(type)
{
    this->nameLength = strlen(name);
    this->name = new char[this->nameLength + 1];
    strcpy_s(this->name, this->nameLength + 1, name);
}

Account::~Account()
{
    if (name != nullptr)
    {
        delete[] name;
    }
}

void Account::Deposit(int amount)
{
    this->balance += amount;

    FILE* file = nullptr;

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

const char* Account::Serialize()
{
    char* buffer = new char[256];

    snprintf(buffer, 256, "id: %d, name: %s , balance: %d, type: %s \n",
        id, name, balance, "Normal");

    return buffer;
}
