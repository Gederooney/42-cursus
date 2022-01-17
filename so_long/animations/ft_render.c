/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:40:18 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 11:58:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

void	ft_fill_linea(char *line, t_world *w, int i)
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
			mlx_put_image_to_window(w->i, w->wn, w->ep, 16 * j, 16 * i);
			w->x = j;
			w->y = i;
		}
		line++;
		j++;
	}
}

void	ft_animrender(t_world *w)
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
		ft_fill_linea(line, w, i);
		i++;
		j++;
	}
	line = ft_itoa(w->mv);
	mlx_string_put(w->i, w->wn, 32, 16, 0xffffff, "Moves: ");
	mlx_string_put(w->i, w->wn, 100, 16, 0xffffff, line);
	free(line);
}
