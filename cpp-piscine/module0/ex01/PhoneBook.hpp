/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:12:13 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 14:24:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

int	isOnlyDigits(std::string str);

class PhoneBook
{
	private:
		Contact	contact_list[8];
		int		count;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		add_contact(void);
		std::string	parse_input(std::string input);
		void	search_contact(void);
		Contact	get_contact_infos(void);
};

#endif
