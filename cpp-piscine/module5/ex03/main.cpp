/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:01:14 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 12:15:15 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main(void)
{
    Form *f1;
    Form *f2;
    Form *f3;
    Form *f4;
    Intern i1;
    Bureaucrat b1 = Bureaucrat("Mr. Abraham", 42);

    f1 = i1.makeForm("robotomy request", "Marvin");
    f2 = i1.makeForm("presidential pardon", "Marvin");
    f3 = i1.makeForm("shrubbery creation", "Marvin");
    std::cout << *f1 << std::endl;
    std::cout << *f2 << std::endl;
    std::cout << *f3 << std::endl;

    b1.signForm(*f1);
    b1.executeForm(*f1);

    f4 = i1.makeForm("TEST", "Marvin");

    return (0);
}
