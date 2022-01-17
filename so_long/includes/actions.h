/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:30:45 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 08:00:32 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "./so_long.h"
# include "../includes/utils.h"

void	ft_handle_left(t_world *w);
void	ft_handle_right(t_world *w);
void	ft_handle_up(t_world *w);
void	ft_handle_down(t_world *w);

#endif
