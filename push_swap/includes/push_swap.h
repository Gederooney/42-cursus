/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 08:25:35 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 18:41:18 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_hold
{
	size_t	hold_f;
	size_t	hold_s;
	int		best;
}	t_hold;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		*c;
	int		max;
	int		bit_max;
	size_t	sa;
	size_t	sb;
	size_t	sc;
	size_t	min_c;
	size_t	max_c;
}	t_stacks;

int			main(int argc, char **argv);
t_stacks	*ft_parse(char **arguments);
int			ft_checkchar(char *i);
int			ft_checkinputs(char **arguments);
int			ft_arg_is_int(long x);
t_stacks	*ft_initstacks(size_t n);
void		ft_fillstack(int n, t_stacks *stacks, char **argument);
void		ft_sa(int *a, size_t *x);
void		ft_sb(int *b, size_t *y);
void		ft_ss(int *a, int *b, size_t *x, size_t *y);
void		ft_shift_left(int *tab, size_t n);
void		ft_shift_right(int	*tab, size_t n);
void		ft_pa(int *a, int *b, size_t *x, size_t *y);
void		ft_pb(int *b, int *a, size_t *y, size_t *x);
void		ft_ra(int *a, size_t *x);
void		ft_rb(int *b, size_t *y);
void		ft_rr(int *a, int *b, size_t *x, size_t *y);
void		ft_rra(int *a, size_t *x);
void		ft_rrb(int *b, size_t *y);
void		ft_rrr(int *a, int *b, size_t *x, size_t *y);
void		ft_sort_three(t_stacks *s);
void		ft_sort_five(t_stacks *s);
void		ft_radix_sort(t_stacks *s);
void		ft_make_key(int *to_key, int *sorted, size_t count);
void		ft_cleanb(t_stacks *s);
void		ft_resolve(t_stacks *s);

#endif
