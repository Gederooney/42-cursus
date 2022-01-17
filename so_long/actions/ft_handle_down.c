/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:30:13 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:12:42 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/actions.h"

void	ft_handle_down(t_world *w)
{
	char	**map;
	char	*line;
	char	*next;

	map = w->m;
	line = map[w->y - 3];
	next = map[w->y - 2];
	if (next[w->x] == '0' || next[w->x] == 'C')
	{
		mlx_put_image_to_window(w->i, w->wn, w->pl, 16 * (w->x),
			16 * (w->y + 1));
		mlx_put_image_to_window(w->i, w->wn, w->ep, 16 * w->x, 16 * w->y);
		if (next[w->x] == 'C')
			w->sc += 10;
		line[w->x] = '0';
		next[w->x] = 'P';
		w->y += 1;
		w->mv += 1;
		ft_render_map(w);
	}
	else if (next[w->x] == 'E' && (w->g == w->sc))
		ft_freegame(w);
}
