/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:21:38 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 16:24:53 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	rtn;

	rtn = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 0)
	{
		rtn *= nb;
		power--;
	}
	return (rtn);
}
