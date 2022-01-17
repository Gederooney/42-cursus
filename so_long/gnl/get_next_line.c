/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:19:52 by ryebadok          #+#    #+#             */
/*   Updated: 2021/08/09 10:17:04 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_myfree(void *ptr)
{
	if (ptr)
	{
		free (ptr);
		return (1);
	}
	return (0);
}

char	*ft_getline(char *save, char **line)
{
	char	*temp;

	if (ft_strchr(save, 10))
	{
		*line = ft_substr(save, 0, ft_strchr(save, 10) - save);
		temp = ft_strdup(ft_strchr(save, 10) + 1);
		ft_myfree (save);
		return (temp);
	}
	*line = ft_strdup(save);
	ft_myfree(save);
	return (NULL);
}

char	*ft_readmore(char *save, int fd, int *res)
{
	char	*content;
	char	*temp;

	content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	temp = ft_strjoin(save, NULL);
	ft_myfree(save);
	while (*res > 0 && !ft_strchr(temp, 10))
	{
		*res = read(fd, content, BUFFER_SIZE);
		if (*res == -1 && ft_myfree(content) && ft_myfree(temp))
			return (NULL);
		content[*res] = 0;
		save = ft_strjoin(temp, content);
		ft_myfree(temp);
		temp = ft_strdup(save);
		ft_myfree(save);
	}
	ft_myfree(content);
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			res;

	res = 1;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	save = ft_readmore(save, fd, &res);
	if (!save)
		return (-1);
	save = ft_getline(save, line);
	if (res > 0)
		return (1);
	else if (res == 0 && !save)
		return (0);
	return (1);
}
