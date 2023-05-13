/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:29:39 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/23 18:01:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &uneInstance )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = uneInstance;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const & aCopier )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = aCopier.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "getRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
