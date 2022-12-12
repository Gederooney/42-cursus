/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:11:35 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/11 21:02:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone_book.hpp"

Phone_book::Phone_book(void){
	count = 0;
}

int	Phone_book::add_contact(void)
{
	Contact contact = get_contact_infos();
	if (!cin.eof())
	{
		contact.set_id(count);
		if (count < 8)
			contact_list[count] = contact;
		else
			contact_list[count % 8] = contact;
		count++;
		return (1);
	}
	return (0);
}

string	Phone_book::parse_input(string input){
	size_t	i = 0;

	while ( i < input.size())
	{
		if(input[i] == ' ')
		{
			i++;
			continue;
		}
		break;
	}
	if (i == input.size())
		return ("");
	else
		return input.substr(i);
}

Contact	Phone_book::get_contact_infos(void)
{
	string	user_input;
	string	fields[4] = {"nickName","firstName", "lastName", "phoneNumber"};
	int		step;
	Contact	tmp;

	step = 0;
	user_input = "";
	while (step != 4 && !cin.eof())
	{
		cout << "Enter a " + fields[step] + " ";
		getline(cin, user_input);
		if (user_input.empty())
			continue;
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
