/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 02:35:20 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/25 12:37:41 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/push_swap.h"

void	ft_free_intarray(int *s, size_t count);
int		ft_array_issorted(int *array, size_t n);
int		ft_sort_intarray(int *array, size_t n);
int		ft_copyarray(int *src, int *dest, size_t n);
int		ft_get_max(int *a, size_t n);
int		ft_get_min(int *s, size_t n);
int		ft_ismin(int min, int *s, size_t n);
int		ft_ismax(int max, int *s, size_t n);
size_t	ft_indexofm(int *s, size_t n);

#endif
