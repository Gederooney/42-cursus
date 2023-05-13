/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:23:02 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/14 10:24:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <fstream>

class Form;

class PresidentialPardonForm : public Form
{
	protected:
		std::string _target;
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		void execute(Bureaucrat const & executor) const;
};

#endif
