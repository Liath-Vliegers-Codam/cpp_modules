/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 15:28:51 by anonymous     #+#    #+#                 */
/*   Updated: 2025/04/01 15:28:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	if (time->tm_mday < 10)
	{
		std::cout << "0";
	}
	std::cout << time->tm_mday;
	std::cout << "_";
	std::cout << time->tm_hour;
	std::cout << time->tm_min;
	std::cout << time->tm_sec;
	std::cout << "] ";
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
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
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
	std::cout << "created";
	std::cout << std::endl;
}

// deconstructor
Account::~Account(void)
{
	// [19920104_091532] index:7;amount:8942;closed
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}
