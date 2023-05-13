/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:27:07 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 12:15:47 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern {
	public:
		Intern(const Intern & src);
		~Intern();
		Intern();

		Intern & operator=(const Intern & rhs);

		Form *makeForm(std::string formName, std::string target);

		typedef Form* (Intern::*MakeFormFunc)(std::string);

	private:
		static const std::string FORMS_Names[3];
		static MakeFormFunc FORMS_Funcs[3];
		Form *makePresidentialPardonForm(std::string target);
		Form *makeRobotomyRequestForm(std::string target);
		Form *makeShrubberyCreationForm(std::string target);
};

#endif
