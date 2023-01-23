/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:29:39 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/21 16:34:34 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed& uneInstance )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = uneInstance;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( int const n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed( float const f )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(f * (1 << this->_fractionalBits));
}

Fixed&	Fixed::operator=( Fixed const& aCopier )
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
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream&	operator<<( std::ostream & o, Fixed const &i )
{
	o << i.toFloat();
	return o;
}
