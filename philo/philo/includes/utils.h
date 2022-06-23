/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:58:32 by ryebadok          #+#    #+#             */
/*   Updated: 2022/06/23 07:42:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"
# include "limits.h"

size_t		ft_get_time(void);
int			ft_atoi(const char *str);
int			ft_charprt_len(char **p);
long long	ft_atol(const char *str);
bool		ft_only_num(const char *s);
bool		ft_n_usleep(t_thread *t, size_t now, size_t count);
bool		ft_print_status(t_thread *t, size_t now);

#endif
