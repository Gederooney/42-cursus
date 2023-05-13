/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:39:23 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 10:42:47 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
	if (this != &rhs) {
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > getGradeToExecute()) {
		throw Form::GradeTooLowException();
	}
	if (!getSigned()) {
		throw Form::NotSignedException();
	}

	std::ofstream file;
	file.open(_target + "_shrubbery");
	file << "         v" << std::endl;
	file << "        >X<" << std::endl;
	file << "         A" << std::endl;
	file << "        d$b" << std::endl;
	file << "      .d\\$$b." << std::endl;
	file << "    .d$i$$\\$$b." << std::endl;
	file << "   .d$$@b\\$$$ib." << std::endl;
	file << "  .d$$i$$b\\$$$$b." << std::endl;
	file << "  d$$$$@$b\\$$$$$i" << std::endl;
	file << " d$$$$$$i$$b\\$$$b" << std::endl;
	file << "d$$$$$$$$@$b\\$$$i" << std::endl;
	file << "$$$$$$$$$$$b\\$$b" << std::endl;
	file << "$$$$$$$$$$$$b\\$$" << std::endl;
	file << "$$$$$$$$$$$$$$@>" << std::endl;
	file << "$$$$$$$$$$$$$$i" << std::endl;
	file << "iiiiiiiiiiiiiiii" << std::endl;
	file.close();
}
