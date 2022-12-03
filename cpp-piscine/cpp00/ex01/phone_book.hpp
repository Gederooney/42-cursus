/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:43:56 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/02 22:11:15 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "contact.hpp";
# include <string>;

using namespace std;

class PhoneBook
{
	public:
	private:
	vector<Contact>contact_list[8];
};

#endif
