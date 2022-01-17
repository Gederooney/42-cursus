/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:23 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/16 12:26:50 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*rtn;

	rtn = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (rtn);
}
