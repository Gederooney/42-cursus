/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebdok@student.42quebec.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:29:12 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/23 18:47:01 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else
		return (-1);
}

void	ft_rev_table(int n, char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	j = i + 1;
	while (i < n)
	{
		while (j < n)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(int n, char *argv[])
{
	int	i;

	i = 1;
	ft_rev_table(n, argv);
	while (i < n)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		i++;
		write(1, "\n", 1);
	}
}
