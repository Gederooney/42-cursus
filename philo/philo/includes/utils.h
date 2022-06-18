/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:58:32 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/18 10:17:43 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

bool		ft_only_num(const char *s);
int			ft_atoi(const char *str);
int			ft_charprt_len(char **p);
void		ft_shift_left(size_t *tab, size_t n);
void		ft_ra(size_t *a, size_t x);
int			*ft_create_queu(int n);
size_t		ft_get_time(void);
void		ft_print_arr(size_t count, size_t *array);
void		ft_printer(t_thread *t);
bool		ft_eating(t_thread *t);
bool		ft_feed_last(t_thread *t);
bool		ft_feed_not_last(t_thread *t);
void		ft_usleep(size_t t);
#endif
