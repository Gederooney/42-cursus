/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:26:11 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 12:11:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*line;
	struct s_list	*next;
}	t_list;

//wd = width
//hg = height
//rw = rows
//cl = columns
//x = position->x
//y = position->y
//sc = score
//map = map
//wl = wall
//ep = empty
//clb = collectible
//ex = exit
//p = initial position
//pl = player image
//i = init
//wn = window
//mv = moves
//g = score to end game
typedef struct s_world
{
	double	s;
	char	d;
	int		wd;
	int		hg;
	int		rw;
	int		cl;
	int		x;
	int		y;
	int		sc;
	int		g;
	int		mv;
	char	**m;
	void	*wl;
	void	*ep;
	void	*clb;
	void	*ex;
	void	*p;
	void	*h;
	void	*pl;
	void	*i;
	void	*wn;
	void	*pl_r1;
	void	*pl_r2;
	void	*pl_r3;
	void	*ps;
}	t_world;

typedef struct s_pl
{
	double	x;
	double	y;
	char	d;
}	t_pl;

t_list	*ft_read_map(char *filename);
int		ft_onlywall(char *line);
int		ft_wallborder(t_list *map);
t_list	*ft_parse(char *filename);
t_world	*ft_create_world(t_list *map);
char	**ft_create_map(t_list *map);
t_world	*ft_init(t_list *map);
void	ft_render_map(t_world *w);
void	ft_run(t_list *map);
int		ft_freegame(t_world *w);
void	ft_error(int code);
void	ft_next_error(int code);
void	ft_move_forwad(t_world *w);
void	ft_move_back(t_world *w);
void	ft_fill_linea(char *line, t_world *w, int i);
void	ft_animrender(t_world *w);
void	ft_putplayerf(t_world *w);

#endif
