#include "DonationAccount.h"

void DonationAccount::Deposit(int amount)
{
	this->balance += amount;

	int donationAmount = (int)balance * 0.01;
	this->balance -= donationAmount;

	this->donationAmount += donationAmount;

	std::cout << "������ �ݾ� : " << CheckBalance() << ", ����� �� �ݾ� : " << GetDonationAmount() << '\n';
}
