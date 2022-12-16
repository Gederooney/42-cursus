/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:00:43 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 09:40:00 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce();
		void	setName(std::string name);
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
Zombie*	zombieHorde( int N, std::string name );

#endif
