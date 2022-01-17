/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:21:23 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:43:30 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Cette fonction parse les inputs de l'utilisation à l'aide
	des deux fonctions ci dessous et retourne une stack rempli
	initialisée.
*/
t_stacks	*ft_parse(char **arguments)
{
	int			count;
	t_stacks	*stacks;

	count = 0;
	if (!arguments || ft_checkinputs(arguments))
		return (NULL);
	while (arguments[count])
		count++;
	stacks = ft_initstacks(count);
	ft_fillstack(count, stacks, arguments);
	return (stacks);
}

/*
	Cette fonction vérifie que les entrées de l'utiisateurs
	respectent le format indiqué. Les nombres doivent être tous
	ne doivent pas se repéter...
*/
int	ft_checkinputs(char **arguments)
{
	char	**j;
	char	*i;

	while (*arguments)
	{
		j = arguments + 1;
		i = *arguments;
		while (*j)
		{
			if (ft_atol(i) == ft_atol(*j))
				return (1);
			j++;
		}
		if (ft_checkchar(i) || ft_arg_is_int(ft_atol(i)))
			return (1);
		arguments++;
	}
	return (0);
}

/*
	Cette fonction vérifie si les entrées de l'utilisateurs sont
	tous des int
*/
int	ft_arg_is_int(long x)
{
	return (x < INT_MIN || x > INT_MAX);
}

int	ft_checkchar(char *i)
{
	char	*start;

	start = i;
	while (*i)
	{
		if ((!('0' <= *i && *i <= '9') && *i != ' ' && *i != '-')
			|| (*i == '-' && i != start && *(i - 1) != ' '))
			return (1);
		i++;
	}
	return (0);
}

/*
	La fonction fill_stacks comme son nom l'indique,
	rempli la stack initiale a par les valeurs parsées.
	Il lui faut le nombre de int en arguments et aussi,
	une instance de la structure des stacks.
*/
void	ft_fillstack(int n, t_stacks *stacks, char **argument)
{
	int	i;

	i = 0;
	while (i < n)
	{
		stacks->a[i] = ft_atoi(argument[i]);
		stacks->sa += 1;
		i++;
	}
}
