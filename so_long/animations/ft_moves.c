/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:52:46 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:16:39 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"
#include <stdio.h>

void	ft_putplayerf(t_world *w)
{
	int		x;
	int		y;
	char	**map;
	char	*line;

	w->s += 0.25;
	x = (16 * (w->x + 1));
	y = 16 * w->y;
	map = w->m;
	line = map[w->y - 3];
	if (w->s == 0.75)
		w->s = 0;
	if (w->s == 0)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r1, x, y);
	else if (w->s == 0.25)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r2, x, y);
	else if (w->s == 0.5)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r3, x, y);
	if (line[w->x + 1] == 'C')
		w->sc += 10;
	line[w->x + 1] = 'P';
	line[w->x] = '0';
	w->x += 1;
}

void	ft_putplayerb(t_world *w)
{
	int		x;
	int		y;
	char	**map;
	char	*line;

	w->s += 0.25;
	x = (16 * (w->x - 1));
	y = 16 * w->y;
	map = w->m;
	line = map[w->y - 3];
	if (w->s == 0.75)
		w->s = 0;
	if (w->s == 0)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r3, x, y);
	else if (w->s == 0.25)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r2, x, y);
	else if (w->s == 0.5)
		mlx_put_image_to_window(w->i, w->wn, w->pl_r1, x, y);
	if (line[w->x - 1] == 'C')
		w->sc += 10;
	line[w->x - 1] = 'P';
	line[w->x] = '0';
	w->x -= 1;
}

void	ft_move_forwad(t_world *w)
{
	char	**map;
	char	*line;

	map = w->m;
	line = map[w->y - 3];
	if (line[w->x + 1] == '0' || line[w->x + 1] == 'C')
	{
		w->mv += 1;
		ft_animrender(w);
		ft_putplayerf(w);
	}
	else if (line[w->x + 1] == 'E' && (w->g == w->sc))
		ft_freegame(w);
}

void	ft_move_back(t_world *w)
{
	char	**map;
	char	*line;

	map = w->m;
	line = map[w->y - 3];
	if (line[w->x - 1] == '0' || line[w->x - 1] == 'C')
	{
		w->mv += 1;
		ft_animrender(w);
		ft_putplayerb(w);
	}
	else if (line[w->x - 1] == 'E' && (w->g == w->sc))
		ft_freegame(w);
}
