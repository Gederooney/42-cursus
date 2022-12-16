/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:36:14 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 10:25:30 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

using namespace std;

class Weapon
{
	private:
		string _type;

	public:
		Weapon(string type);
		~Weapon();
		
		string const &getType();
		void setType(string type);
};

#endif