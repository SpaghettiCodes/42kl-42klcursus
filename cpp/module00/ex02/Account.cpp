#include "Account.hpp"
#include <iostream>

/* 
	add this to silent the warning 
	"re warning: relocation against `_ZN7Account19_totalNbWithdrawalsE' in read-only section `.text" 
	error that makes you unable to compile jackshit 
	(i thought statics are automatically assigned 0 what the fuck?)
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbDeposits);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout <<  "accounts:" << getNbAccounts() << ";"; 
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "closed" << std::endl;
}

Account::Account (void)
{
	
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const
{
	return (_amount);
}

#include <time.h>

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	tm *nowtime;
	time_t sec_passed;

	sec_passed = time(NULL);
	nowtime = gmtime(&sec_passed);
	std::cout << "[";
	std::cout << nowtime->tm_year + 1900 << nowtime->tm_mon << nowtime->tm_mday << "_";
	std::cout << nowtime->tm_hour << nowtime->tm_min << nowtime->tm_sec;
	std::cout << "] ";
}

//yearmndt_hrscmn
//i think.