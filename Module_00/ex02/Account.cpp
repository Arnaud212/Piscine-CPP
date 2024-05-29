#include <iostream>
#include <iomanip>
#include "Account.hpp"
#include <ctime>

    int Account::_nbAccounts = 0;
    int Account::_totalAmount = 0;
    int Account::_totalNbDeposits = 0;
    int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::Account()
{
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void     Account::_displayTimestamp()
{
    struct tm *stime;
	time_t	ttime;

	time(&ttime);
	stime = localtime(&ttime);
	std::cout << "[" << stime->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << stime->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << stime->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << stime->tm_hour;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << stime->tm_min;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << stime->tm_sec << "] ";

	//std::cout << "[19920104_091532] ";
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    this->_nbDeposits += 1;
    this->_totalAmount += deposit;
    this->_totalNbDeposits += 1;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;   
}

int     Account::getNbAccounts()
{
    return (_nbAccounts);
}

int     Account::getTotalAmount()
{
    return (_totalAmount);
}

int     Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int     Account::checkAmount(void) const
{
    return (this->_amount > 0);
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

