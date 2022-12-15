/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:56:18 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/15 13:18:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// constructor of the class
Contact::Contact(void)
{
	// initialize all the attributes and assign a default value to each of them
	id = 0;
	nick_name = "";
	first_name = "";
	last_name = "";
	phone_number = "";
};

// Destructor of the class
Contact::~Contact(void)
{
	// there is nothing to destruct in this class
}

// this is the global setter of the class
// its assign each property of the class a value depending on 
// the param received.
void	Contact::set_field(string field, string value)
{
	if (field == "nickName")
		this->nick_name = value;
	else if (field == "firstName")
		this->first_name = value;
	else if (field == "lastName")
		this->last_name = value;
	else if (field == "phoneNumber")
		this->phone_number = value;
}

// this is the setter for the contact id;
void	Contact::set_id(int i){
	this->id = i;
}

// this is the getter, returning the contact id;
int		Contact::get_id(void){
	return this->id;
}

// this function takes a string and format it to return a new 
// string ready to be displayed according to what is asked in the
// exercice
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

// function that displays a contact
void	Contact::display(void)
{
	std::cout << "         " + to_string(id) + "|" << trimOrAddSpaces(first_name) +"|" << trimOrAddSpaces(last_name)+"|" << trimOrAddSpaces(nick_name)<< std::endl;
}

// this function displays the contact infos one line at the time
void	Contact::displayLineByLine(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nick name: " << nick_name << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
}
