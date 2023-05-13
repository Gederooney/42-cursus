/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:00:06 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 11:03:33 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool	ClapTrap::state = true;

/*
** Default constructor
*/
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
** Constructor with name
*/
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

/*
** Copy constructor
*/
ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

/*
** Destructor
*/
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*
** Overload of the assignation operator
*/
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

/*
** member functions (accessors)
** name: getName
** description: returns the name of the ClapTrap
** return: std::string
*/
std::string ClapTrap::getName() const
{
	return (this->_name);
}

/*
** member functions (mutators)
** name: setName
** description: sets the name of the ClapTrap
** return: void
*/
void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

/*
** member functions (mutators)
** name: setAttackDamage
** description: sets the attack damage of the ClapTrap
** return: void
*/
void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

/*
** member functions (accessors)
** name: getAttackDamage
** description: returns the attack damage of the ClapTrap
** return: unsigned int
*/ 
unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

/*
** member functions (mutators)
** name: setHitPoints
** description: sets the hit points of the ClapTrap
** return: void
*/
void ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

/*
** member functions (accessors)
** name: getHitPoints
** description: returns the hit points of the ClapTrap
** return: unsigned int
*/
unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

/*
** member functions (mutators)
** name: setEnergyPoints
** description: sets the energy points of the ClapTrap
** return: void
*/
void ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

/*
** member functions (accessors)
** name: getEnergyPoints
** description: returns the energy points of the ClapTrap
** return: unsigned int
*/
unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

/*
** member functions
** name: attack
** description: attacks a target
** parameters: target (string name of target)
** return: void
*/
void ClapTrap::attack(std::string const& target)
{
	if(this->_energyPoints < 1 || this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

/*
** member functions
** name: takeDamage
** description: takes damage
** parameters: amount (unsigned int amount of damage)
** return: void
*/
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		ClapTrap::state = false;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	
}

/*
** member functions
** name: beRepaired
** description: repairs the ClapTrap
** parameters: amount (unsigned int amount of repair)
** return: void
*/
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}
