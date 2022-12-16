/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:35:59 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/16 09:52:34 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int 	main(void)
{
	string	brain;
	string	*brainPtr;
	string	&brainRef = brain;
	

	brain = "HI THIS IS BRAIN";
	brainPtr = &brain;

	{
		cout << "brain: " << &brain << endl;
		cout << "brainPtr: " << brainPtr << endl;
		cout << "brainRef: " << &brainRef << endl;
	}
	{
		cout << "value in brain: " << brain << endl;
		cout << "value pointed by brainPtr: " << *brainPtr << endl;
		cout << "value pointed by brainRef: " << brainRef << endl;
	}
	return (0);
}
