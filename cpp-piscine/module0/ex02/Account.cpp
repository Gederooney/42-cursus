/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:10:58 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 17:54:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;
	
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:"<< Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;
	
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbWithdrawals += 1;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" <<  p_amount + deposit << "nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;
	Account::_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;

		std::cout << "index:"<< this->_accountIndex << ";p_amount:" << p_amount << ";withdrawals:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else {
		std::cout << "index:"<< this->_accountIndex << ";amount:" << this->_amount << ";withdrawals:refused" << std::endl;
		return false;
	}
}

int	Account::checkAmount (void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";amount:" << this->_amount << ";deposit:" << this->_nbDeposits  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << " [19920104_091532]";
}
