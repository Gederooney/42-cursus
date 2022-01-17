/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadpk@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:43:35 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 17:00:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;
	int	sqrt;

	x = nb;
	sqrt = 1;
	if (nb < 0)
		return (0);
	while (x > sqrt)
	{
		x = (x + sqrt) / 2;
		sqrt = nb / x;
	}
	if (nb == x * x)
		return (x);
	return (0);
}
