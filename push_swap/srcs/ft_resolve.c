/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:00:24 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/10 10:13:53 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"
#include "../includes/new_sort.h"

void	ft_resolve(t_stacks *s)
{
	if (s->sa == 1)
		return ;
	else if (s->sa == 2)
		ft_sa(s->a, &s->sa);
	else if (s->sa == 3)
		ft_sort_three(s);
	else if (s->sa <= 5)
		ft_sort_five(s);
	else if (s->sa <= 100)
		ft_newsort(s);
	else
		ft_radix_sort(s);
}
