/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:38:39 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 12:22:40 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

// virtual AMateria* clone() const = 0;
void AMateria::use(ICharacter& target) {
	std::cout << "* Materia is not ice and cure called by:" << target.getName() << " *" << std::endl;
}
