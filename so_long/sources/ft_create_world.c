/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:13:26 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 12:18:18 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"

char	**ft_create_map(t_list *map)
{
	int		c;
	char	**rtn;
	char	**s;
	t_list	*f;

	c = ft_lstsize(map);
	rtn = malloc(sizeof(char *) * (c + 1));
	s = rtn;
	while (map)
	{
		*s = map->line;
		f = map;
		map = map->next;
		s++;
		free(f);
	}
	free(map);
	*s = NULL;
	return (rtn);
}

//Cette fonction crée une ligne à la fois du monde
void	ft_fill_line(char *line, t_world *w, int i)
{
	int	j;

	j = 0;
	while (*line)
	{
		if (*line == '1')
			mlx_put_image_to_window(w->i, w->wn, w->wl, 16 * j, 16 * i);
		else if (*line == '0')
			mlx_put_image_to_window(w->i, w->wn, w->ep, 16 * j, 16 * i);
		else if (*line == 'C')
			mlx_put_image_to_window(w->i, w->wn, w->clb, 16 * j, 16 * i);
		else if (*line == 'E')
			mlx_put_image_to_window(w->i, w->wn, w->ex, 16 * j, 16 * i);
		else if (*line == 'P')
		{
			mlx_put_image_to_window(w->i, w->wn, w->ps, 16 * j, 16 * i);
			w->x = j;
			w->y = i;
		}
		line++;
		j++;
	}
}

//Cette fonction crée le monde
t_world	*ft_create_world(t_list *map)
{
	t_world	*w;
	int		i;
	int		j;
	char	*line;

	i = 3;
	j = 0;
	w = ft_init(map);
	if (!w)
		return (NULL);
	while ((w->m)[j])
	{
		line = (w->m)[j];
		ft_fill_line(line, w, i);
		while (*line)
		{
			if (*line == 'C')
				w->g += 10;
			line++;
		}
		i++;
		j++;
	}
	return (w);
}

//Cette re-affiche la map
void	ft_render_map(t_world *w)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < w->cl)
			mlx_put_image_to_window(w->i, w->wn, w->h, 16 * j++, 16 * i);
		i++;
	}
	j = 0;
	while ((w->m)[j])
	{
		line = (w->m)[j];
		ft_fill_line(line, w, i);
		i++;
		j++;
	}
	line = ft_itoa(w->mv);
	mlx_string_put(w->i, w->wn, 32, 16, 0xffffff, "Moves: ");
	mlx_string_put(w->i, w->wn, 100, 16, 0xffffff, line);
	free(line);
}
