/*

Exercise : 02
The Job Of Your Dreams

Turn-in directory	: ex02/
Files to turn in	: Makefile, Account.cpp, Account.hpp, tests.cpp
Forbidden functions	: None

Account.hpp, tests.cpp, and the log file are available for download on the module’s intranet page.

Today is your first day at GlobalBanksters United. After successfully passing the recruitment tests 
(thanks to a few Microsoft Office tricks a friend showed you), you joined the dev team. 
You also know the recruiter was amazed by how quickly you installed Adobe Reader. 
That little extra made all the difference and helped you defeat all your opponents (aka the other applicants): you made it!
Anyway, your manager just gave you some work to do. Your first task is to recreate a lost file. 
Something went wrong and a source file was deleted by mistake. 
Unfortunately, your colleagues don’t know what Git is and use USB keys to share code. 
At this point, it would make sense to leave this place right now. However, you decide to stay. Challenge accepted!
Your fellow developers give you a bunch of files. Compiling tests.cpp reveals that the missing file is Account.cpp. 
Lucky you, the header file Account.hpp was saved.
There is also a log file. Maybe you could use it in order to understand how the Account class was implemented.

You start to recreate the Account.cpp file. In only a few minutes, you code a few lines of pure awesome C++. 
After a couple of failed compilations, your program passes the tests. 
Its output matches perfectly the one saved in the log file 
(except for the timestamps which will obviously differ since the tests saved in the log file were run before you were hired).
Damn, you’re impressive!
The order in which the destructors are called may differ depending on your compiler/operating system. 
So your destructors may be called in a reverse order.
Completing exercise 02 is not mandatory to pass this module.

*/


// static int	_nbAccounts;
// static int	_totalAmount;
// static int	_totalNbDeposits;
// static int	_totalNbWithdrawals;

// int			_accountIndex;
// int			_amount;
// int			_nbDeposits;
// int			_nbWithdrawals;

#include "Account.hpp"
#include <iostream>
#include <ctime>




int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;



int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayAccountsInfos(void)
{
	// [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;

}

void	Account::displayStatus(void) const
{
	// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *time = std::localtime(&now);

	// [19920104_091532]
	std::cout << "[";
	std::cout << (time->tm_year + 1900);
	if ((time->tm_mon + 1) < 10)
	{
		std::cout << "0";
	}
	std::cout << (time->tm_mon + 1);
	std::cout << time->tm_mday;
	std::cout << "_";
	std::cout << time->tm_hour;
	std::cout << time->tm_min;
	std::cout << time->tm_sec;
	std::cout << "] ";
}


	
void	Account::makeDeposit(int deposit)
{
	// [19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;
	_nbDeposits++;
	
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	
	if (withdrawal <= this->_amount)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		
		_amount -= withdrawal;
		_nbWithdrawals++;
		
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
		
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		return (true);
	}

	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

}

// constructor
Account::Account(int initial_deposit)
{
	// [19920104_091532] index:0;amount:42;created
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created:";
	std::cout << std::endl;
	

}

// deconstructor
Account::~Account(void)
{
	// [19920104_091532] index:7;amount:8942;closed
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed:";
	std::cout << std::endl;
}
