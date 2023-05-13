/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:20:23 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/13 17:44:39 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdea (i, src.brain->getIdea(i));
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->brain = rhs.getBrain();
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

/* ************************************************************************** */
