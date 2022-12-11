/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:11:35 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/10 17:41:30 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone_book.hpp"

Phone_book::Phone_book(void){
	count = 0;
}

int	Phone_book::parse_command()
{
	string	command = "";
	if(command != "EXIT")
	{
		if (cin.eof())
		{
			cout << "this \n";
		}
		else if (command == "ADD")
			add_contact();
		else if (command == "SEARCH")
			search_contact();
		cout << "Enrter a command: ";
		cin >> command;
		parse_command();
	}
	return (0);
}

void	Phone_book::add_contact(void)
{
	Contact contact = get_contact_infos();
	contact.set_id(count);
	
	if (count < 8)
		contact_list[count] = contact;
	else
		contact_list[count % 8] = contact;
	count++;
}

Contact	Phone_book::get_contact_infos(void)
{
	string	user_input;
	string	fields[4] = {"nickName","firstName", "lastName", "phoneNumber"};
	int		step;
	Contact	tmp;

	step = 0;
	user_input = "";
	while (step != 4)
	{
		cout << "Enter a " + fields[step] + " ";
		
		tmp.set_field(fields[step], user_input);
		step++;
	}
	return (tmp);
}

void	Phone_book::search_contact()
{
	int	i;
	int	limit;

	i = 0;
	if (count < 8)
		limit = count;
	else 
		limit = 8;
	while (i < limit)
	{
		contact_list[i].display();
		i++;
	}
}
