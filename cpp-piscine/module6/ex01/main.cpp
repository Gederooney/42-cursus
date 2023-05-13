/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:04:33 by ryebadok          #+#    #+#             */
/*   Updated: 2023/05/10 11:25:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main (void)
{
	Data *data = new Data;
	data->s1 = "Hello in the world";
	data->n = 42;
	data->s2 = "Goodbye in the world";
	
	std::cout << "data->s1: " << data->s1 << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data->s2: " << data->s2 << std::endl;

	uintptr_t raw = serialize(data);
	Data *data2 = deserialize(raw);

	std::cout << "data2->s1: " << data2->s1 << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;
	std::cout << "data2->s2: " << data2->s2 << std::endl;

	delete data;
	return (0);
}
