/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:25:40 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:12:34 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/actions.h"
#include "../includes/get_next_line.h"

int	ft_handle_key(int key, t_world	*w)
{
	if (key == 53)
		ft_freegame(w);
	else if (key == 0 || key == 123)
		ft_move_back(w);
	else if (key == 1 || key == 125)
		ft_handle_down(w);
	else if (key == 2 || key == 124)
		ft_move_forwad(w);
	else if (key == 13 || key == 126)
		ft_handle_up(w);
	return (0);
}

void	ft_run(t_list *map)
{
	t_world	*w;
	int		i;
	int		k;

	i = 0;
	w = ft_create_world(map);
	if (!w)
		ft_freegame(w);
	while (i < 3)
	{
		k = 0;
		while (k < w->cl)
			mlx_put_image_to_window(w->i, w->wn, w->h, 16 * k++, 16 * i);
		i++;
	}
	ft_render_map(w);
	mlx_hook(w->wn, 17, 0L, ft_freegame, w);
	mlx_hook(w->wn, 02, 1L << 0, ft_handle_key, w);
	mlx_loop(w->i);
}
