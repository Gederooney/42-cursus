/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:56:10 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 11:01:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	
	public:
		static bool		state;
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();
		
		ClapTrap& operator=(const ClapTrap& src);

		void			setName(std::string name);
		void 			setHitPoints(unsigned int amount);
		void			setEnergyPoints(unsigned int amount);
		void			setAttackDamage(unsigned int amount);

		std::string		getName() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getHitPoints() const;
		unsigned int	getAttackDamage() const;
		
		void			attack(std::string const& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
