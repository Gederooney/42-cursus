/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:58:32 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 11:45:45 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"

int			ft_atoi(const char *str);
int			ft_charprt_len(char **p);
void		ft_shift_left(int *tab, int n);
void		ft_ra(int *a, int x);
int			*ft_create_queu(int n);
long long	ft_get_time(void);

#endif