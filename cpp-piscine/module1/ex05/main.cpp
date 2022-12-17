/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:46:23 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/17 13:48:59 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl instance;
	void (Harl::*complain)(std::string level);

	complain = &Harl::complain;
	
	(instance.*complain)("DEBUG");
	return (0);
}
