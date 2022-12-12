/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:01 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/11 20:33:22 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

string	get_command(void)
{
	string	command = "";
	cout << "Entrez une command entre ADD SEARCH ET EXIT  ";
	while (getline(cin, command))
	{
		if (command == "SEARCH" || command == "ADD" || command == "EXIT")
			return command;
		cout << "Entrez une commande correcte  ";
	}
	return "ERROR";
}

int main(int n, char **v)
{
	Phone_book	phone_book;
	string command;

	if (n == 2)
	{
		command = v[1];
		while (1)
		{
			if (command == "ERROR" || command == "EXIT")
				return (0);
			else {
				if (command == "ADD")
					phone_book.add_contact();
				else if (command == "SEARCH")
					phone_book.search_contact();
				if (!cin.eof())
					command = get_command();
				else 
					break;
			}
		}
	}
	return 0;
}
