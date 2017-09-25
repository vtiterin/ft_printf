/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fheX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:32:09 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:32:14 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexp1(t_fl *fl, intmax_t num)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_putstr("0X");
		while (fl->width > fl->accur)
		{
			ft_putchar('0');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
	}
	else
	{
		while (fl->width > fl->accur && num >= 0)
		{
			ft_putchar(' ');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
		if (fl->grid == 1)
			ft_putstr("0X");
	}
}

void	ft_hexp2(size_t *len, t_fl *fl)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_putstr("0X");
		while (fl->width > (fl->accur - (int)(*len)))
		{
			ft_putchar('0');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
	}
	else
	{
		while (fl->width > (fl->accur - (int)(*len)))
		{
			ft_putchar(' ');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
		if (fl->grid == 1)
			ft_putstr("0X");
	}
}

void	ft_hexp3(size_t *len, t_fl *fl)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_putstr("0X");
		while (fl->width > (int)(*len))
		{
			ft_putchar('0');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
	}
	else
	{
		while (fl->width > (int)(*len))
		{
			ft_putchar(' ');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
		if (fl->grid == 1)
			ft_putstr("0X");
	}
}

int		ft_pr_argx(intmax_t num, t_fl *fl)
{
	if (fl->t && num == 0)
	{
		while (fl->width)
		{
			ft_putchar(' ');
			fl->width--;
			fl->ret = fl->ret + 1;
		}
		return (1);
	}
	return (0);
}
