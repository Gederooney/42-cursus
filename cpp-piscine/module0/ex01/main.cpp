/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:01 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 13:15:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <iostream>


static string	get_command(void)
{
	string	command = "";
	std::cout << "Enter a command  ";
	while (getline(std::cin, command))
	{
		if (command == "SEARCH" || command == "ADD" || command == "EXIT")
			return command;
		std::cout << "Enter a valid command ";
	}
	return "ERROR";
}

static void	menu(void)
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	PhoneBook	PhoneBook;
	string command;

	menu();
	while (1)
	{
		if (command == "ERROR" || command == "EXIT")
			return (0);
		else {
			if (command == "ADD")
				PhoneBook.add_contact();
			else if (command == "SEARCH")
				PhoneBook.search_contact();
			if (!std::cin.eof())
				command = get_command();
			else 
				break;
		}
	}
	
	return 0;
}
