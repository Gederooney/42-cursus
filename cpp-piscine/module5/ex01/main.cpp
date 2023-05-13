/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:01:14 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 09:25:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try{
		Form form("text form", 118, 1);
		Bureaucrat bureaucrat("Bureaucrat", 12);
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
