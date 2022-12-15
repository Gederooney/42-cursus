/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:25 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 13:28:35 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact{

	private:
		int		id;
		string	nick_name;
		string	first_name;
		string	last_name;
		string	phone_number;
	
	public:
		Contact(void);
		~Contact(void);
		
		void	set_field(string field, string value);
		int		get_id(void);
		void	set_id(int i);
		void	display(void);
		void	displayLineByLine(void);
		string	trimOrAddSpaces(string s);
};

#endif
