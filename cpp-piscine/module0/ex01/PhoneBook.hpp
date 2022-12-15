/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:12:13 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 11:32:28 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

using namespace std;

int	isOnlyDigits(string str);

class PhoneBook
{
	private:
		Contact	contact_list[8];
		int		count;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		add_contact(void);
		string	parse_input(string input);
		void	search_contact(void);
		Contact	get_contact_infos(void);
};

#endif
