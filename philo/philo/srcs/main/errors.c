/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:26:08 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 10:27:56 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include "../../includes/srcs.h"

/*
	Cette fonction gère les erreurs et affichent des messages à l'utilisateur
	
	Valeurs possibles de code:
		100 ==> pas d'arguments ou trop d'arguments
*/
int	ft_errors(int code)
{
	write (1, "Error\n", 6);
	if (code == 100)
		write (1, "Vous devez avoir 4 ou 5 arguments\n", 34);
	else if (code == 200)
		printf("Il y a eu une erreur. Vérifiez vos arguments et relancez\n");
	return (0);
}
