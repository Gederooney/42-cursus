/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:17:25 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 12:32:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();
		
		Animal & operator=(Animal const & rhs);
		
		virtual void makeSound() const;
		std::string getType() const;
		
	protected:
		std::string _type;
};

#endif
