/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:56:18 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/04 21:46:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	id = 0;
	nick_name = "";
	first_name = "";
	last_name = "";
	phone_number = "";
};
void	Contact::set_field(string field, string value)
{
	if (field == "nickname")
		nick_name = value;
	else if (field == "firstName")
		first_name = value;
	else if (field == "lastName")
		last_name = value;
	else if (field == "phoneNumber")
		phone_number = value;
	cout << nick_name << endl;
}
void	Contact::set_id(int i){
	id = i;
}

void	Contact::display(void)
{
	cout << first_name;
}
