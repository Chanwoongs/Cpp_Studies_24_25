#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount() : donationAmount(0) {}
	DonationAccount(int id, const char* name, AccountType type)
		: Account(id, name, type), donationAmount(0)
	{ }
	~DonationAccount() {}

	virtual void Deposit(int amount) override;
    virtual const char* Serialize() override;

	const int GetDonationAmount() const { return donationAmount; }

private:
	int donationAmount;
};

