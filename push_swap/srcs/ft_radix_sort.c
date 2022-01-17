/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:10:42 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:22:48 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/utils.h"
#include <stdio.h>

void	ft_make_key(int *to_key, int *sorted, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (to_key[i] == sorted[j])
			{
				to_key[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_insert_a(t_stacks *s, size_t c)
{
	size_t	i;

	i = 0;
	if (c)
	{
		ft_pb(s->b, s->a, &s->sb, &s->sa);
		while (++i < c)
			ft_rra(s->a, &s->sa);
		ft_pa(s->a, s->b, &s->sa, &s->sb);
		while (i--)
			ft_ra(s->a, &s->sa);
	}
	else
		ft_ra(s->a, &s->sa);
}

void	ft_insert_b(t_stacks *s, size_t c)
{
	size_t	i;

	i = 0;
	if (c)
	{
		ft_pa(s->a, s->b, &s->sa, &s->sb);
		while (++i < c && s->a[0] < s->b[s->sb - 1])
			ft_rrb(s->b, &s->sb);
		ft_pb(s->b, s->a, &s->sb, &s->sa);
		while (i--)
			ft_rb(s->b, &s->sb);
	}
	else
		ft_rb(s->b, &s->sb);
	s->min_c += 1;
}

void	ft_clean_b(t_stacks *s, int i)
{
	size_t	j;

	while (i < s->bit_max)
	{
		j = 0;
		while (j < s->sc - s->max_c)
		{
			if ((s->a[0] >> i) & 1)
				ft_ra(s->a, &s->sa);
			else
				ft_pb(s->b, s->a, &s->sb, &s->sa);
			j++;
		}
		i++;
		while (s->sb)
			ft_pa(s->a, s->b, &s->sa, &s->sb);
	}
}

void	ft_radix_sort(t_stacks *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	ft_copyarray(s->a, s->c, s->sa);
	s->sc = s->sa;
	ft_sort_intarray(s->c, s->sc);
	ft_make_key(s->a, s->c, s->sa);
	s->max = s->sa - 1;
	while (s->max >> s->bit_max)
		++s->bit_max;
	ft_clean_b(s, i);
}
