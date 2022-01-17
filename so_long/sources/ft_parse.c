/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:03:51 by ryebadok          #+#    #+#             */
/*   Updated: 2021/10/06 17:53:54 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"

/*
*	Cette fonction prends en paramètre une map déjà lue et transformée
*	en liste chaînée et vérfie si elle conitent les caractères qui sont
*	obligatoires. Soit dans ce contexte, la Position d'entrée, celle de
*	sortie et un collectible
*/
int	ft_required_char(t_list *map)
{
	char	*line;
	int		c;
	int		p;
	int		e;

	c = 0;
	p = 0;
	e = 0;
	while (map)
	{
		line = map->line;
		while (*line)
		{
			if (*line == 'C')
				c += 1;
			else if (*line == 'P')
				p += 1;
			else if (*line == 'E')
				e += 1;
			line++;
		}
		map = map->next;
	}
	return (c && e == 1 && p == 1);
}

/*
*	Cette Fonction vérifie si une ligne de la map contient
*	que des caractères wall de la map 
*	Elle retourne 0 sinon et 1 si oui
*/
int	ft_onlywall(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

/*
*	Cette Fonction vérifie si toutes les lignes
*	de la map sont bien délimitées par les murs
*	Elle retourne 0 sinon et 1 si oui
*/
int	ft_wallborder(t_list *map)
{
	char	*temp;

	if (!ft_onlywall(ft_lstlast(map)->line) || !ft_onlywall(map->line))
	{
		ft_error(202);
		return (0);
	}
	while (map)
	{
		temp = map->line;
		if (*temp != '1' || temp[ft_strlen(temp) - 1] != '1')
		{
			ft_error(202);
			return (0);
		}
		map = map->next;
	}
	return (1);
}

/*
*	Cette Fonction vérifie si toutes les lignes de la map
*	ont la même taille et que tous les caractères sont valides.
*	 Elle retourne < 0 sinon et 1 si oui
*/
int	ft_size_onlyc(t_list *map)
{
	int		count;
	char	*line;

	count = ft_lstsize(map);
	while (map)
	{
		line = map->line;
		if ((ft_strlen(map->line) < count)
			|| (map->next && ft_strlen(map->line)
				!= ft_strlen(map->next->line)))
			return (-2);
		while (*line)
		{
			if (*line != '0' && *line != '1' && *line != 'C'
				&& *line != 'P' && *line != 'E')
			{
				ft_error(203);
				return (0);
			}
			line++;
		}
		map = map->next;
	}
	return (1);
}

/*
*	Cette fonction est celle qui analyse les données reçues de 
*	l'utilisateur. Son paramètre doit être le chemin absolue vers
*	le fichier de la map. Elle retroune 1 si la map respecte toutes
*	les conditions et 0 sinon.
*/
t_list	*ft_parse(char *filename)
{
	t_list	*map;
	t_list	*start;

	map = ft_read_map(filename);
	if (!map)
		return (NULL);
	start = map->next;
	free(map);
	map = start;
	if (!ft_wallborder(map) || !ft_size_onlyc(map))
		return (ft_freestruct(map));
	else if (!ft_required_char(map))
	{
		ft_error(203);
		return (ft_freestruct(map));
	}
	else if (ft_size_onlyc(map) == -2)
	{
		ft_error(206);
		return (ft_freestruct(map));
	}
	return (start);
}
