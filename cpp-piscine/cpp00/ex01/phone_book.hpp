/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:12:13 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/10 17:37:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

using namespace std;

class Phone_book
{
	private:
		Contact contact_list[8];
		int		count;
	public:
		Phone_book(void);
		int		parse_command();
		void	add_contact(void);
		void	search_contact(void);
		Contact	get_contact_infos(void);
};

#endif
