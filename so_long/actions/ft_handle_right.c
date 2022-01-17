/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:30:13 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:12:51 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/actions.h"

void	ft_handle_right(t_world *w)
{
	char	**map;
	char	*line;

	map = w->m;
	line = map[w->y - 3];
	if (line[w->x + 1] == '0' || line[w->x + 1] == 'C')
	{
		mlx_put_image_to_window(w->i, w->wn, w->pl, 16 * (w->x + 1), 16 * w->y);
		mlx_put_image_to_window(w->i, w->wn, w->ep, 16 * w->x, 16 * w->y);
		if (line[w->x + 1] == 'C')
			w->sc += 10;
		line[w->x + 1] = 'P';
		line[w->x] = '0';
		w->x += 1;
		ft_render_map(w);
	}
	else if (line[w->x + 1] == 'E' && (w->g == w->sc))
		ft_freegame(w);
}
