#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount() : donationAmount(0) {}
	DonationAccount(int id, const char* name)
		: Account(id, name), donationAmount(0)
	{ }
	~DonationAccount() {}

	virtual void Deposit(int amount) override;

	const int GetDonationAmount() const { return donationAmount; }

private:
	int donationAmount;
};
