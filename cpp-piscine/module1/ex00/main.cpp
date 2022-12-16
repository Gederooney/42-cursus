/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:00:23 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 09:30:14 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *ryebadok;

	ryebadok = newZombie("Ryebadok");
	ryebadok->announce();
	
	delete ryebadok;
	randomChump("Mgnangni");
	return 0;
}
