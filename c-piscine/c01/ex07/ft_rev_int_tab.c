/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:41:21 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/15 08:56:36 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = size;
	while (i > (size / 2))
	{
		temp = tab[i - 1];
		tab[i - 1] = tab[size - i];
		tab[size - i] = temp;
		i--;
	}
}
