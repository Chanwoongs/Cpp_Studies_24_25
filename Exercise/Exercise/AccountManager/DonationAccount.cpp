#include "DonationAccount.h"

void DonationAccount::Deposit(int amount)
{
    Account::Deposit(amount);

	int donationAmount = (int)balance * 0.01;
    Account::Withdrawal(donationAmount);

	this->donationAmount += donationAmount;

	std::cout << "저축한 금액 : " << CheckBalance() << ", 기부한 총 금액 : " << GetDonationAmount() << '\n';
}
