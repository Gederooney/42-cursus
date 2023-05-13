/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:31:09 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 12:14:46 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::FORMS_Names[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern() {
}

Intern::Intern(const Intern & src) {
	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(const Intern & rhs) {
	if (this != &rhs) {
		// do stuff
	}
	return *this;
}

Form *Intern::makePresidentialPardonForm(std::string target) {
	std::cout << "Intern creates presidential pardon" << std::endl;
	return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string target) {
	std::cout << "Intern creates robotomy request" << std::endl;
	return new RobotomyRequestForm(target);
}

Form *Intern::makeShrubberyCreationForm(std::string target) {
	std::cout << "Intern creates shrubbery creation" << std::endl;
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string formName, std::string target) {
	Form *form = NULL;
	int i = 0;
	while (i < 3) {
		if (formName == FORMS_Names[i]) {
			form = (this->*FORMS_Funcs[i])(target);
			break;
		}
		i++;
	}
	return form;
}

Intern::MakeFormFunc Intern::FORMS_Funcs[3] = {
	&Intern::makePresidentialPardonForm,
	&Intern::makeRobotomyRequestForm,
	&Intern::makeShrubberyCreationForm
};

// Path: ex03/main.cpp
