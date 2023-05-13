/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:33:46 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 12:19:42 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;


	class AMateria
	{
		protected:
			std::string _type;
		
		public:
			AMateria();
			AMateria(std::string const & type);
			AMateria(AMateria const & src);
			virtual ~AMateria();
			
			AMateria & operator=(AMateria const & rhs);
	
			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
	};

#endif
