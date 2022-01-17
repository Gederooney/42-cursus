/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:59:59 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 12:12:37 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"

void	ft_intit_images(t_world *w)
{
	int	hg;
	int	wd;

	hg = w->hg;
	wd = w->wd;
	w->h = mlx_xpm_file_to_image(w->i, "./assets/h.xpm", &wd, &hg);
	w->wl = mlx_xpm_file_to_image(w->i, "./assets/wl.xpm", &wd, &hg);
	w->ep = mlx_xpm_file_to_image(w->i, "./assets/ep.xpm", &wd, &hg);
	w->clb = mlx_xpm_file_to_image(w->i, "./assets/clb.xpm", &wd, &hg);
	w->ex = mlx_xpm_file_to_image(w->i, "./assets/ex.xpm", &wd, &hg);
	w->p = mlx_xpm_file_to_image(w->i, "./assets/p.xpm", &wd, &hg);
	w->pl = mlx_xpm_file_to_image(w->i, "./assets/pl.xpm", &wd, &hg);
	w->pl_r1 = mlx_xpm_file_to_image(w->i, "./assets/pl_r1.xpm", &wd, &hg);
	w->pl_r2 = mlx_xpm_file_to_image(w->i, "./assets/pl_r2.xpm", &wd, &hg);
	w->pl_r3 = mlx_xpm_file_to_image(w->i, "./assets/pl_r3.xpm", &wd, &hg);
	w->ps = mlx_xpm_file_to_image(w->i, "./assets/ps.xpm", &wd, &hg);
}

//Cette fonction initialise toutes les variables dans la struct world
void	ft_init_const(t_world *w)
{
	w->d = 0;
	w->s = 0;
	w->wd = 16;
	w->hg = 16;
	w->sc = 0;
	w->g = 0;
	w->mv = 0;
	w->i = mlx_init();
	w->wn = mlx_new_window(w->i, 16 * w->cl, (w->rw + 3) * 16, "So_long");
}

t_world	*ft_init(t_list *map)
{
	t_world	*w;

	w = malloc(sizeof(t_world) * 1);
	if (!w)
		return (NULL);
	w->cl = ft_strlen(map->line);
	w->rw = ft_lstsize(map);
	w->m = ft_create_map(map);
	ft_init_const(w);
	ft_intit_images(w);
	return (w);
}
