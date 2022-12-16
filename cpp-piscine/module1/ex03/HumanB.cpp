/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:42:26 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 11:22:49 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	std::cout << "constructor called without a name" << std::endl;
}

HumanB::HumanB(std::string name, Weapon &weapon): _name(name), _weapon(&weapon)
{
	std::cout << "constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "destructor called for HumanB" << std::endl;
}

void HumanB::attack()
{
	cout << this->_name << " attacks with his " << this->_weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/* ************************************************************************** */
