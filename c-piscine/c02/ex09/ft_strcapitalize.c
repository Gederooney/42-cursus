/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:27:38 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/18 14:05:14 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_alpha_num(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'C'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_num (char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*rtn;

	rtn = str;
	while (*str)
	{
		if (*str >= 32 && *str < 127)
		{
			if (str == rtn && ft_is_lowercase(*str))
				*str = *str - 32;
			else if (ft_is_uppercase (*(str - 1)) && ft_is_uppercase(*str))
				*str = *str + 32;
			else if (ft_is_lowercase(*(str - 1)) && ft_is_uppercase(*str))
				*str = *str + 32;
			else if (ft_is_num(*(str - 1)) && ft_is_uppercase(*str))
				*str = *str + 32;
			else if (!ft_is_alpha_num(*str) && *(str + 1))
			{
				if (ft_is_lowercase(*(str + 1)))
					*(str + 1) = *(str + 1) - 32;
			}
		}
		str++;
	}
	return (rtn);
}
