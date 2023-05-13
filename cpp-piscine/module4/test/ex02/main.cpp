/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:16:45 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 12:55:59 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

Animal **createAnimal(unsigned int count)
{
	Animal **rtn = new Animal*[count * 2];
	if (count == 0)
		return NULL;
	for (unsigned int i = 0; i < count; i++)
	{
		if (i % 2 == 0)
			rtn[i] = new Dog();
		else
			rtn[i] = new Cat();
	}
	
	return rtn;
}

void deleteAnimal(Animal **animals, unsigned int count)
{
	if (count == 0)
		return;
	for (unsigned int i = 0; i < count; i++)
		delete animals[i];
	delete [] animals;
}

int main()
{
	unsigned int count = 10;
	Animal **animals = createAnimal(count);

	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		std::cout << animals[i]->getType() << std::endl;
	}
	deleteAnimal(animals, count);
	return 0;
}
