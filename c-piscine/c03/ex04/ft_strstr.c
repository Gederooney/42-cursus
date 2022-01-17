/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:49:44 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/18 17:39:59 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(char *X, char *Y)
{
	while (*X && *Y)
	{
		if (*X != *Y)
			return (0);
		X++;
		Y++;
	}
	return (*Y == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
