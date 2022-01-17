/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:10 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 17:37:05 by ryebadok         ###   ########.fr       */
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
	return (x);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	i = 2;
	sqrt = ft_sqrt(nb);
	if (nb < 2)
		return (0);
	while (i <= sqrt)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}
