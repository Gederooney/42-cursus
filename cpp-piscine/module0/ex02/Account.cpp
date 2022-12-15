/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:10:58 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 15:17:29 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

using namespace std;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
	_displayTimestamp();
}

void	Account::makeDeposit(int deposit)
{
}

bool	Account::makeWithdrawal(int withdrawal)
{
}

int		Account::checkAmount(void) const
{
}

void	Account::displayStatus(void) const
{
}

static void _displayTimestamp(void)
{
}

