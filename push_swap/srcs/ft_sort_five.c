/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 04:21:03 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/10 10:19:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

//get index of min
size_t	ft_indexofmin(int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		if (ft_ismin(s[i++], s, n))
			return (i - 1);
	return (n + 1);
}

/*
	Move the minimum number from a to b
*/
void	ft_move_to_b(t_stacks *s)
{
	size_t	idofm;

	idofm = ft_indexofmin(s->a, s->sa);
	if (idofm <= s->sa / 2)
		while (!ft_ismin(s->a[0], s->a, s->sa))
			ft_ra(s->a, &s->sa);
	else
		while (!ft_ismin(s->a[0], s->a, s->sa))
			ft_rra(s->a, &s->sa);
	ft_pb(s->b, s->a, &s->sb, &s->sa);
}

/*
	Cette fonction permet de trier un tableau de 5 nombres en utilisant un
	autre tableau totalement vides. Le nombre de movement maximun est 12
*/
void	ft_sort_five(t_stacks *s)
{
	while (s->sa && !ft_array_issorted(s->a, s->sa))
	{
		if (s->a[0] > s->a[1])
			ft_sa(s->a, &s->sa);
		if (!ft_array_issorted(s->a, s->sa) && s->sa > 2)
			ft_move_to_b(s);
	}
	while (s->sb)
		ft_pa(s->a, s->b, &s->sa, &s->sb);
}
