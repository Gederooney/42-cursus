/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:36:01 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 17:49:35 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type) : _type(type)
{
	_type = type;
}

Weapon::~Weapon()
{
}

string const &Weapon::getType()
{
	return (_type);
}

void Weapon::setType(string type)
{
	_type = type;
}

/* ************************************************************************** */