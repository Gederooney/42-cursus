/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:35:26 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 12:10:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name),  ScavTrap(name) , FragTrap(name)
{
	this->_name = name;
	std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: " << this->_name << " is actually ClapTrap: " << this->ClapTrap::getName() << std::endl;
}
