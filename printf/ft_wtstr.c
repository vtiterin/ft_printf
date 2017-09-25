/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:37:55 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:37:59 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wpr_p1(t_fl *fl, int y)
{
	while ((fl->accur - y) > 0)
	{
		if (fl->zero > 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->ret += 1;
		fl->accur--;
	}
}

void	ft_wpr_p(int len, wchar_t *value, t_fl *fl)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (fl->accur < len && fl->accur > 0)
	{
		len = ft_wchlen(value[x]);
		while (fl->accur >= len)
		{
			if (value[x + 1])
				y = ft_wchlen(value[x + 1]);
			if (y < fl->accur && (fl->width >= fl->accur))
				ft_wpr_p1(fl, y);
			fl->ret += ft_putwch(value[x]);
			if (((fl->accur - len) >= 0))
				fl->accur -= len;
			x++;
			len = ft_wchlen(value[x]);
		}
	}
	else
		fl->ret += ft_putwstr(value);
}

void	ft_wpr_base(int len, t_fl *fl)
{
	if ((fl->width > fl->accur) && (fl->accur < len) && (fl->accur > 0))
		len = fl->accur;
	while (fl->width > len)
	{
		if (fl->zero > 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->width--;
		fl->ret = fl->ret + 1;
	}
}

void	ft_wstrnul(t_fl *fl)
{
	ft_putstr("(null)");
	fl->ret += 6;
}

void	ft_str_ss(t_fl *fl)
{
	wchar_t	*value;
	int		len;

	value = va_arg(fl->arg, wchar_t *);
	if (!value)
		ft_wstrnul(fl);
	else if (fl->minus == 0)
	{
		if (ft_pr_args(fl))
			return ;
		else
		{
			len = ft_wstrlen(value);
			ft_wpr_base(len, fl);
			ft_wpr_p(len, value, fl);
		}
	}
	else
	{
		if (ft_pr_args(fl))
			return ;
		fl->ret += len = ft_wstrlen(value);
		ft_putwstr(value);
		ft_wpr_base(len, fl);
	}
}
