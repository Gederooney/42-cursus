/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:39:26 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 11:04:06 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("Player 1");
	ClapTrap p2("Player 2");

	p1.setAttackDamage(1);
	p2.setAttackDamage(2);

	while (p1.getHitPoints() > 0 && p2.getHitPoints() > 0 && ClapTrap::state)
	{
		p1.attack(p2.getName());
		p2.takeDamage(p1.getAttackDamage());
		p2.attack(p1.getName());
		p1.takeDamage(p2.getAttackDamage());
	}
	std::cout << "Game Over" << std::endl;
	return (0);
}
