/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:36:16 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:19 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vprintf(t_fl *fl, const char *format, char *str)
{
	while (format[fl->i])
	{
		if (format[fl->i] != '%')
		{
			ft_putchar(format[fl->i]);
			fl->ret++;
			fl->i++;
		}
		else
		{
			fl->i = fl->i + 1;
			if (str[fl->i] != '\0')
				ft_solve(str, fl);
			ft_initialization(fl);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_fl	*fl;
	char	*str;
	int		r;

	str = (char *)format;
	fl = (t_fl *)malloc(sizeof(*fl));
	ft_initialization(fl);
	fl->ret = 0;
	fl->i = 0;
	if (!format)
		return (-1);
	va_start(fl->arg, format);
	ft_vprintf(fl, format, str);
	va_end(fl->arg);
	r = fl->ret;
	free(fl);
	return (r);
}
