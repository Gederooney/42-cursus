/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:26:54 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/25 11:39:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** Default constructor
*/
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

/*
** Constructor
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "ScavTrap constructor called" << std::endl;
}

/*
** Copy constructor
*/
ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

/*
** Destructor
*/
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

/*
** Assignation operator overload
*/
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &src)
	{
		this->setName(src.getName());
		this->setHitPoints(src.getHitPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	return *this;
}

/*
** Methods
*/

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}

