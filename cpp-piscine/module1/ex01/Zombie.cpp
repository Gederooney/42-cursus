/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:09 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 09:43:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Created without a name" << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Created with a name" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructed" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name +":"<< " BraiiiiiiinnnzzzZ..." << std::endl;
}


void	Zombie::setName(std::string name)
{
	_name = name;
}

Zombie* newZombie( std::string name )
{
	Zombie* newZombie = new Zombie(name);
	return newZombie;
}

void randomChump( std::string name )
{
	Zombie newZombie = Zombie(name);
	newZombie.announce();
}
