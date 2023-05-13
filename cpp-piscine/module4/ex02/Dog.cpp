/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:22:22 by ryebadok          #+#    #+#             */
/*   Updated: 2023/03/08 14:17:27 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woufff" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}

Animal* Dog::clone() const
{
	return new Dog(*this);
}

/* ************************************************************************** */
