/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 08:18:49 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:16:57 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_sort.h"

void	ft_cleana(t_stacks *s)
{
	size_t	i;
	size_t	j;
	int		m;

	m = ft_get_min(s->a, s->sa)
		+ ((ft_get_max(s->a, s->sa) - ft_get_min(s->a, s->sa)) / 2);
	while (s->sa && s->a[0] < m && s->sa > 2)
		ft_pb(s->b, s->a, &s->sb, &s->sa);
	while (s->sa && s->a[s->sa - 1] < m && s->sa > 2)
	{
		ft_rra(s->a, &s->sa);
		ft_pb(s->b, s->a, &s->sb, &s->sa);
	}
	j = s->sa;
	i = 0;
	while (i < j && s->sa > 2)
	{
		if (s->a[0] >= m)
			ft_ra(s->a, &s->sa);
		else
			ft_pb(s->b, s->a, &s->sb, &s->sa);
		i++;
	}
	if (s->sa == 2 && !ft_array_issorted(s->a, s->sa))
		ft_sa(s->a, &s->sa);
}

void	ft_cleanb(t_stacks *s)
{
	size_t	idofm;

	while (s->sb)
	{
		idofm = ft_indexofm(s->b, s->sb);
		if (ft_get_max(s->b, s->sb) != s->b[0])
		{
			if (s->sb >= 2 && ft_get_max(s->b, s->sb) == s->b[1])
				ft_sb(s->b, &s->sb);
			else if (idofm < s->sb && idofm < (s->sb / 2))
				while (ft_indexofm(s->b, s->sb) != 0)
					ft_rb(s->b, &s->sb);
			else
				while (ft_indexofm(s->b, s->sb) != 0)
					ft_rrb(s->b, &s->sb);
		}
		ft_pa(s->a, s->b, &s->sa, &s->sb);
	}
	while (s->a[0] != ft_get_min(s->a, s->sa))
		ft_rra(s->a, &s->sa);
}

void	ft_newsort(t_stacks *s)
{
	while (s->sa > 2)
		ft_cleana(s);
	ft_cleanb(s);
}
