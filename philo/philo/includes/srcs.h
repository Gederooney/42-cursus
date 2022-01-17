/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:57:15 by ryebadok          #+#    #+#             */
/*   Updated: 2021/11/19 11:10:17 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

int		ft_errors(int code);
t_var	*ft_parse(char **arg, int n);
void	*ft_routine(void *arg);
t_g		**ft_initthreads(t_var *v);

#endif