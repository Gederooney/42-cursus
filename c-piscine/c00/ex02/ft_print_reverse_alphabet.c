/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rony Gédéon <ryebadok@student.42quebec.com>+#+       +:+       +#+   */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:01:09 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/13 15:37:23 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_print_reverse_alphabet(void)
{
	int	i;

	i = 122;
	while (i > 96)
	{
		write(1, &i, 1);
		i--;
	}
}
