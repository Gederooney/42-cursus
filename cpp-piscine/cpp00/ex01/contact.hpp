/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:25 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/04 07:32:18 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

using namespace std;

class Contact{

	private:
		int		id;
		string	nick_name;
		string	first_name;
		string	last_name;
		string	phone_number;
	
	public:
		Contact(void);
		void	set_field(string field, string value);
		void	set_id(int i);
		void	display(void);
};

#endif
