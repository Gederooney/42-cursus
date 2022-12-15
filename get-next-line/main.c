/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:34:31 by ryebadok          #+#    #+#             */
/*   Updated: 2022/12/12 18:55:30 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	**line;
	int		fd;
	int		i;
	int		n;

	fd = open ("text.txt", O_RDONLY);
	line = malloc(sizeof(char *) * 1);
	i = 1;
	n = 0;
	while (i > 0)
	{
		i = get_next_line(fd, line);
		printf("%s\n", *line);
	}
	return (0);
}