/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:29:35 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/21 17:44:37 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed();

		Fixed&	operator=(Fixed const &aCopier);
		
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++(void);
		Fixed&	operator--(void);

		bool	operator>(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;

		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		
		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static Fixed const &	min(Fixed const &a, Fixed const &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);
		
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;
	
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<( std::ostream & o, Fixed const &i );

#endif
