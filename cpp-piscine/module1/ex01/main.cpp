/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:21:08 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 09:44:30 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	zombies = zombieHorde(5, "Ryebadok");
	for (int i = 0; i < 5; i ++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
