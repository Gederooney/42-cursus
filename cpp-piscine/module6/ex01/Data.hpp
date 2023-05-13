/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:36:53 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/02 08:37:52 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
