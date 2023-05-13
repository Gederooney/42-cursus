/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:58:00 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 17:03:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

Form::~Form() {}

Form & Form::operator=(const Form & rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return (*this);
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

void Form::signForm(Bureaucrat & bureaucrat) {
	try {
		this->beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	catch (std::exception & e) {
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << " because " << e.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* Form::AlreadySignedException::what() const throw() {
	return ("Form already signed");
}


