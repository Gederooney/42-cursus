/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:46:46 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 12:16:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

t_list	*ft_freestruct(t_list *s)
{
	t_list	*temp;

	while (s)
	{
		temp = s;
		s = s->next;
		free(temp->line);
		free(temp);
	}
	return (NULL);
}
