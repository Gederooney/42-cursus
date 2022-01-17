/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:32:16 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/20 09:48:07 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		ft_sa(s->a, &s->sa);
	else if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		ft_ra(s->a, &s->sa);
		ft_sa(s->a, &s->sa);
	}
	else if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] > s->a[2])
		ft_ra(s->a, &s->sa);
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
		ft_rra(s->a, &s->sa);
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		ft_sa(s->a, &s->sa);
		ft_ra(s->a, &s->sa);
	}
}
