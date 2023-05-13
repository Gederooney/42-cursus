/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:49:36 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 10:31:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <fstream>

class Form;

class RobotomyRequestForm : public Form
{
	protected:
		std::string _target;
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm();
		
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
		
		void execute(Bureaucrat const & executor) const;
};

#endif
