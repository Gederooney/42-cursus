/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:22:25 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 17:39:20 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct  s_infos
{
	int	m;
	int	pl;
	int	s;
	int	h;
	int	z;
	int	w;
	int p;
	int l;
	int	err;
} t_infos;

void	ft_printwidth(int n);
int		ft_convertc(const char *s, va_list args);
int		ft_converts(const char *s, va_list args);
int		ft_convertp(const char *s, va_list args);
int		ft_convertd(const char *s, va_list args);
int		ft_convertx(const char *s, va_list args);
int		ft_convert_X(const char *s, va_list args);
t_infos	*ft_getinfos(const char *s, va_list args);
void	ft_stars(const char *s, t_infos *infos, va_list args);
const char	*ft_doprint(const char *s, va_list args, int *c, size_t *w);
int		ft_getnbrcount(int nbr);
int		ft_isFlag(char c);
int		ft_specifier(char c);
int		ft_writeloop(int n, char c);
size_t	ft_argwidth(const char *arg);
int		ft_printf(const char *format, ...);

#endif