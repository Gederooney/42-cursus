/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:04:20 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 18:27:41 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int n, char *argv[])
{
	int	i;

	i = n;
	while (*argv[0])
	{
		write(1, argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}
