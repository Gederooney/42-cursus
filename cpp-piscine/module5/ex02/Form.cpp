/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:18:53 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 09:45:13 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

Form::~Form() {}

Form & Form::operator=(const Form & rhs) {
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else if (_signed)
		throw Form::AlreadySignedException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "it's already signed";	
}

const char* Form::NotSignedException::what() const throw ()
{
	return "it's not signed";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	o << rhs.getName() << " is a form that requires a grade of " << rhs.getGradeToSign() << " to sign and a grade of " << rhs.getGradeToExecute() << " to execute. It is currently " << (rhs.getSigned() ? "signed" : "unsigned") << std::endl;
	return o;
}
