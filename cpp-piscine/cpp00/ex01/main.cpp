/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:47:01 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:02 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

string	get_command(void)
{
	string	command = "";
	cin >> command;
	cout << command << endl;
	if (cin.eof())
	{
		cout << "here\n";
		cin.clear();
		cin.ignore();
		clearerr(stdin);
	}
	cin >> command;
	cout << command << endl;
	cout << cin.eof() << endl;
	return command;
}

int main(void)
{
	Phone_book	phone_book;
	get_command();
}
