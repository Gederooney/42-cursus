/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:11:35 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 14:08:13 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	count = 0;
}

PhoneBook::~PhoneBook(void)
{
	// nothing to destruct for now
}

int	isOnlyDigits(string str)
{
	size_t	i;

	i = 0;
	while (i < str.size())
	{
		if (isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	PhoneBook::add_contact(void)
{
	Contact contact = get_contact_infos();
	if (!std::cin.eof())
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

string	PhoneBook::parse_input(string input){
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
	input = input.substr(i);
	i = 0;
	while ( i < input.size())
	{
		if(input[i] == ' ')
			break;
		i++;
	}
	input = input.substr(0, i);
	return (input);
}

Contact	PhoneBook::get_contact_infos(void)
{
	string	user_input;
	string	fields[4] = {"nickName","firstName", "lastName", "phoneNumber"};
	int		step;
	Contact	tmp;

	step = 0;
	user_input = "";
	while (step != 4 && !std::cin.eof())
	{
		std::cout << "Enter a " + fields[step] + " ";
		getline(std::cin, user_input);
		user_input = parse_input(user_input);
		if (!user_input.length())
			continue;
		if (step == 3 && !isOnlyDigits(user_input))
			continue;
		tmp.set_field(fields[step], user_input);
		step++;
	}
	return (tmp);
}

void	PhoneBook::search_contact()
{
	int	i, id;
	int	limit;
	string	user_input;

	i = 0;
	if (count == 0)
	{
		std::cout << "No contact to display" << std::endl;
		return ;
	}
	if (count < 8)
		limit = count;
	else 
		limit = 8;
	while (i < limit)
	{
		contact_list[i].display();
		i++;
	}
	std::cout << "Enter the index of the contact to display: ";
	getline(std::cin, user_input);
	i = 0;
	while (!isOnlyDigits(user_input))
	{
		std::cout << "Enter a valid contact ";
		getline(std::cin, user_input);
	}
	id = stoi(user_input);
	i = 0;
	while (i < limit)
	{
		if (contact_list[i].get_id() == id)
			break;
		i++;
	}
	if (i == limit)
		std::cout << "No contact has that index " << std::endl;
	else
		contact_list[i].displayLineByLine();
}
