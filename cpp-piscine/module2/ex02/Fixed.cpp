/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:29:39 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/21 17:47:16 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed & uneInstance )
{
	*this = uneInstance;
}

Fixed::~Fixed()
{
}

Fixed &		Fixed::operator=( Fixed const & aCopier )
{
	this->_fixedPointValue = aCopier.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
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

Fixed::Fixed( int const n )
{
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed( float const f )
{
	this->_fixedPointValue = roundf(f * (1 << this->_fractionalBits));
}

std::ostream&	operator<<( std::ostream & o, Fixed const &i )
{
	o << i.toFloat();
	return o;
}


// les operateurs >, <, >=, <=, == et !=
bool	Fixed::operator>(Fixed const &other) const
{
	return this->_fixedPointValue > other.getRawBits();
}

bool	Fixed::operator<(Fixed const &other) const
{
	return this->_fixedPointValue < other.getRawBits();
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}

bool	Fixed::operator==(Fixed const &other) const
{
	return this->_fixedPointValue == other.getRawBits();
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

// Les 4 opérateurs de arithmétiques : +, -, *, et /.
Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed tmp(*this);
	tmp.setRawBits(this->_fixedPointValue + other.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed tmp(*this);
	tmp.setRawBits(this->_fixedPointValue - other.getRawBits());
	return tmp;
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed tmp(*this);
	tmp.setRawBits((this->_fixedPointValue * other.getRawBits()) >> this->_fractionalBits);
	return tmp;
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed tmp(*this);
	tmp.setRawBits((this->_fixedPointValue << this->_fractionalBits) / other.getRawBits());
	return tmp;
}

// les operateurs ++ et -- (préfixe et postfixe)
Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}


Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}

// min et max
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}
