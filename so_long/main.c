/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:25:35 by ryebadok          #+#    #+#             */
/*   Updated: 2021/09/26 12:43:03 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/actions.h"

/*
*	La fonction de gestion des erreurs qui explique comment fonctionne le
*	programme et comment le lancer.
*	Paramètre: int type qui correspond au code d'erreur
*	Type = 0 => Pas assez d'arguments pour le programme
*	Type = 100 => Trop d'arguments
*	Type = 200 => Invalid map
*/
void	ft_error(int code)
{
	ft_putstr_fd(">>>>>>>>>>>>>><<<<<<<<<<<<<<\n", STDOUT_FILENO);
	ft_putstr_fd("\033[1;31mError\n", STDOUT_FILENO);
	if (code == 0)
		ft_putstr_fd("Passez la map comme argument\n", STDOUT_FILENO);
	else if (code == 100)
	{
		ft_putstr_fd("Trop arguments\n", STDOUT_FILENO);
		ft_putstr_fd("./so_long path_to_map\n", STDOUT_FILENO);
	}
	else if (code >= 200)
	{
		ft_putstr_fd("Votre map est invalid\n", STDOUT_FILENO);
		ft_putstr_fd("Elle doit\n", STDOUT_FILENO);
		if (code == 201)
			ft_putstr_fd("	être rectangulaire\n", STDOUT_FILENO);
		else if (code == 202)
			ft_putstr_fd("	être bornée de 1\n", STDOUT_FILENO);
		else
			ft_next_error(code);
	}
	ft_putstr_fd("\n\033[0;37m>>>>>>>>>>>>>><<<<<<<<<<<<<<\n", STDOUT_FILENO);
}

void	ft_next_error(int code)
{
	if (code == 203)
	{
		ft_putstr_fd("	avoir une sortie\n", STDOUT_FILENO);
		ft_putstr_fd("	avoir une entrée\n", STDOUT_FILENO);
		ft_putstr_fd("	avoir un collectible\n", STDOUT_FILENO);
		ft_putstr_fd("	avoir que des caractères valides\n", STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd("	avoir des lignes de mêmes tailles\n", STDOUT_FILENO);
		ft_putstr_fd("	avoir que des caractères valides\n", STDOUT_FILENO);
	}
}

/*
*	Fonction main.
*	Point d'entrée dans le programme
*/
int	main(int argc, char **argv)
{
	t_list	*map;

	if (argc < 2)
		ft_error(0);
	else if (argc > 2)
		ft_error(100);
	else
	{
		map = ft_parse(argv[1]);
		if (map != NULL)
			ft_run(map);
	}
	return (0);
}
