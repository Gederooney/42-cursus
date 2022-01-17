/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:53:17 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 06:45:49 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"

/*
*	ft_read_map est la fonction qui lie la map envoyée par l'utilisareur
*	elle retourne une liste chainée dont chaque element correspond à une ligne
*	de la map.
*/
t_list	*ft_read_map(char *filename)
{
	char	*line;
	t_list	*map;
	t_list	*new;
	int		fd;
	int		res;

	res = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_error(0);
		return (NULL);
	}
	map = ft_lstnew(NULL);
	while (res)
	{
		res = get_next_line(fd, &line);
		new = malloc(sizeof(t_list));
		new->line = line;
		new->next = NULL;
		ft_lstadd_back(&map, new);
	}
	close(fd);
	return (map);
}
