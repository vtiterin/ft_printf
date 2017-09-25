/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:29:44 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:29:49 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_for_c(t_fl *fl)
{
	while (fl->width > 1)
	{
		if (fl->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->width--;
		fl->ret = fl->ret + 1;
	}
}

void	ft_char(t_fl *fl)
{
	char	ch;
	wchar_t	wch;

	if (fl->len == 'l' || fl->type == 'C')
	{
		wch = va_arg(fl->arg, wchar_t);
		fl->ret += ft_putwch(wch);
	}
	else
	{
		ch = va_arg(fl->arg, int);
		if (fl->minus == 1)
		{
			ft_putchar(ch);
			fl->ret = fl->ret + 1;
			ft_for_c(fl);
		}
		else
		{
			ft_for_c(fl);
			ft_putchar(ch);
			fl->ret = fl->ret + 1;
		}
	}
}
