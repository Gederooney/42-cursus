/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:32:44 by ryebadok          #+#    #+#             */
/*   Updated: 2023/01/25 08:27:27 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"


int main( void ) {
	
	Point const a( float( 2.5 ), float( 7.5 ) );
	Point const b( float( 8.0 ), float( 4.0 ) );
	Point const c( float( 5.5 ), float( 1.0 ) );
	Point const point( float( 6.5 ), float( 4.5 ));

	bool r = bsp( a, b, c, point );
	
	if ( r == true )
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
	return 0;
}
