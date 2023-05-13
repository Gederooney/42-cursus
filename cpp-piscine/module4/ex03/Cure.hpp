/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:33:42 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 11:45:33 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

	class Cure : public AMateria
	{
		public:
			Cure();
			Cure(Cure const & src);
			virtual ~Cure();
			
			Cure & operator=(Cure const & rhs);

			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);
	};

#endif
