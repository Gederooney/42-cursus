/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:21:38 by ryebadok          #+#    #+#             */
/*   Updated: 2021/06/08 15:59:20 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_argwidth(const char *arg)
{
	size_t	width;

	width = 0;
	while (*arg)
	{
		if (ft_specifier(*arg))
			return (width);
		width++;
		arg++;
	}
	return (0);
}

int	ft_doConvert(const char *s, va_list args)
{
	char	c;
	int		count;

	c = s[ft_strlen(s) - 1];
	count = 0;
	if (c == 'c')
		count = ft_convertc(s, args);
	if (c == 'd' || c == 'i')
		count = ft_convertd(s, args);
	else if (c == 's')
		count = ft_converts(s, args);
	else if (c == 'p')
		count = ft_convertp(s, args);
	else if (c == 'x')
		count = ft_convertx(s, args);
	else if (c == 'X')
		count = ft_convert_X(s, args);
	return (count);
}

const char	*ft_doprint(const char *s, va_list args, int *c, size_t *w)
{
	char	*convert;

	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		(*c)++;
		s += 2;
	}
	else if (*s == '%' && *(s + 1) != '%')
	{
		*w = ft_argwidth(s) + 1;
		if (!*w)
			return (NULL);
		convert = ft_substr((const char *)s, 0, *w);
		*c += ft_doConvert(convert, args);
		free(convert);
		s += *w;
	}
	else
	{
		write(1, s++, 1);
		(*c)++;
	}
	return (s);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counts;
	size_t	width;

	va_start(args, format);
	counts = 0;
	while (*format)
		format = ft_doprint(format, args, &counts, &width);
	va_end(args);
	return (counts);
}
