/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:56:18 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 14:06:54 by ryebadok         ###   ########.fr       */
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
	if (field == "nickName")
		nick_name = value;
	else if (field == "firstName")
		first_name = value;
	else if (field == "lastName")
		last_name = value;
	else if (field == "phoneNumber")
		phone_number = value;
}
void	Contact::set_id(int i){
	id = i;
}
int		Contact::get_id(void){
	return id;
}
string	Contact::trimOrAddSpaces(string s)
{
	if(s.size() > 10)
		return (s.substr(0, 9) + ".");
	else if (s.size() < 10)
	{
		while (s.size() < 10)
			s = " " + s;
	}
	return s;
}
void	Contact::display(void)
{
	cout << "         " + to_string(id) + "|" << trimOrAddSpaces(first_name) +"|" << trimOrAddSpaces(last_name)+"|" << trimOrAddSpaces(nick_name)<< endl;
}

void	Contact::displayLineByLine(void)
{
	cout << "First name: " << first_name << endl;
	cout << "Last name: " << last_name << endl;
	cout << "Nick name: " << nick_name << endl;
	cout << "Phone number: " << phone_number << endl;
}
