/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:39:26 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 12:08:48 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamond");
	diamond.whoAmI();
	diamond.attack("Badass");
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	diamond.highFivesGuys();
	// diamond.ClapTrap::_name = "Clap";
	return 0;
}
