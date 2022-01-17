/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freegame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:46:24 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/27 07:04:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/actions.h"

int	ft_freegame(t_world *w)
{
	while (*(w->m))
	{
		free(*(w->m));
		(w->m)++;
	}
	free(*(w->m));
	mlx_destroy_image(w->i, w->pl);
	mlx_destroy_image(w->i, w->clb);
	mlx_destroy_image(w->i, w->ep);
	mlx_destroy_image(w->i, w->ex);
	mlx_destroy_image(w->i, w->p);
	mlx_destroy_image(w->i, w->h);
	mlx_destroy_image(w->i, w->pl_r1);
	mlx_destroy_image(w->i, w->pl_r2);
	mlx_destroy_image(w->i, w->pl_r3);
	mlx_destroy_image(w->i, w->wl);
	mlx_destroy_window(w->i, w->wn);
	exit(0);
	return (1);
}
