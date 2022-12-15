/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:25 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 14:25:39 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact{

	private:
		int		id;
		std::string	nick_name;
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
	
	public:
		Contact(void);
		~Contact(void);
		
		void	set_field(std::string field, std::string value);
		int		get_id(void);
		void	set_id(int i);
		void	display(void);
		void	displayLineByLine(void);
		std::string	trimOrAddSpaces(std::string s);
};

#endif
