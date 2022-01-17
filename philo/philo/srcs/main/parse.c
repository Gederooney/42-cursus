/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:53:42 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 11:59:41 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/philo.h"
#include "../../includes/philo.h"

/*
	arg ==> arguments
	n ==> nombre d'arguments
*/
t_var	*ft_parse(char **arg, int n)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->n = ft_atoi(*(arg++));
	var->td = ft_atoi(*(arg++)) * 1000;
	var->te = ft_atoi(*(arg++)) * 1000;
	var->ts = ft_atoi(*(arg++)) * 1000;
	if (n == 5)
		var->nte = ft_atoi(*arg);
	if (!var->td || !var->te || !var->ts || (n == 5 && !var->nte))
	{
		free(var);
		return (NULL);
	}
	return (var);
}
