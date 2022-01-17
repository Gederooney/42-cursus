/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:48:12 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/23 08:06:24 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*ft_initstacks(size_t n)
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks) * 1);
	if (!s)
		return (NULL);
	s->a = malloc(sizeof(int) * n);
	s->b = malloc(sizeof(int) * n);
	s->c = malloc(sizeof(int) * n);
	if (!s->a || !s->b || !s->c)
		return (NULL);
	s->sa = 0;
	s->sb = 0;
	s->bit_max = 0;
	s->max_c = 0;
	s->min_c = 0;
	s->max = 0;
	return (s);
}
