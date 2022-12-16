/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:41:56 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 11:07:12 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
	std::cout << "constructor called for HumanA" <<std::endl;
}

HumanA::~HumanA()
{
	std::cout << "destructor called for HumanA" << std::endl;
}

void HumanA::attack()
{
	cout << _name << " attacks with his " << _weapon.getType() << endl;
}

/* ************************************************************************** */
