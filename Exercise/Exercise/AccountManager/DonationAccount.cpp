#include "DonationAccount.h"

void DonationAccount::Deposit(int amount)
{
    Account::Deposit(amount);

	int donationAmount = (int)balance * 0.01;
    Account::Withdrawal(donationAmount);

	this->donationAmount += donationAmount;

	std::cout << "저축한 금액 : " << CheckBalance() << ", 기부한 총 금액 : " << GetDonationAmount() << '\n';
}

const char* DonationAccount::Serialize()
{
    char* buffer = new char[256];

    snprintf(buffer, 256, "id: %d, name: %s , balance: %d, type: %s \n",
        id, name, balance, "Donation");

    return buffer;
}