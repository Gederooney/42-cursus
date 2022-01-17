/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 08:19:58 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:48:12 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"
#include <stdio.h>

void	ft_freeatexit(t_stacks *s)
{
	ft_myfree(s->a);
	ft_myfree(s->b);
	ft_myfree(s->c);
	ft_myfree(s);
}

int	ft_print_stacks(t_stacks *s)
{
	size_t	i;

	i = 0;
	printf("\n");
	printf("Stacks\n");
	printf(">>>>>>>>===<<<<<<<<\n");
	while (i < s->sa || i < s->sc)
	{
		if (i < s->sa && i < s->sc)
			printf("  % 5d  |  %- 5d  \n", s->a[i], s->c[i]);
		else if (i < s->sc)
			printf("     |  % -5d  \n", s->c[i]);
		else
			printf("  % 5d  |     \n", s->a[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	ft_exit_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

char	**ft_getagrs(int argc, char **argv)
{
	char	**tmp;

	if (argc == 1)
		return (ft_split(*argv, ' '));
	else
	{
		while (argc--)
		{
			tmp = ft_split(argv[argc], ' ');
			if (ft_arraylen(tmp) != 1)
			{
				ft_freearray(tmp);
				return (NULL);
			}
			ft_freearray(tmp);
		}
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*s;

	if (argc < 2)
		return (ft_exit_error());
	else
		args = ft_getagrs(argc - 1, argv + 1);
	if (args == NULL)
		return (ft_exit_error());
	else
	{
		s = ft_parse(args);
		if (argc == 2)
			ft_freearray(args);
		if (!s)
			return (ft_exit_error());
		if (!ft_array_issorted(s->a, s->sa))
			ft_resolve(s);
		ft_freeatexit(s);
	}
	return (0);
}
