/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:46:46 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 15:56:08 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main (void)
{
	std::string array[] = {"Hello", "World", "How", "Are", "You"};
	iter(array, 5, print);
	return (0);
}
