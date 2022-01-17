/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:27:54 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 18:25:29 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int main(void)
{
	int count;
	int	test;
	
	count = ft_printf("%017.4s|\n", "maman");
	printf("%d\n", count);
	test = printf("%017.4s|\n", "maman");
	printf("%d\n", test);
	return (0);
}