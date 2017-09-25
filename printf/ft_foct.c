/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:32:31 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:32:33 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_octp1(t_fl *fl, intmax_t num)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_putstr("0");
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
			ft_putstr("0");
	}
}

void	ft_proz(size_t *len, t_fl *fl)
{
	ft_putstr("0");
	fl->ret = fl->ret - 1;
	(*len)++;
}

void	ft_octp2(size_t *len, t_fl *fl)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_proz(len, fl);
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
			ft_proz(len, fl);
	}
}

void	ft_octp3(size_t *len, t_fl *fl)
{
	if (fl->zero == 1)
	{
		if (fl->grid == 1)
			ft_proz(len, fl);
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
			ft_proz(len, fl);
	}
}

int		ft_pr_argo(t_fl *fl, intmax_t num)
{
	if (fl->t && num == 0)
	{
		if (fl->grid == 0)
		{
			while (fl->width)
			{
				ft_putchar(' ');
				fl->width--;
				fl->ret = fl->ret + 1;
			}
		}
		else
		{
			while (fl->width > 1)
			{
				ft_putchar(' ');
				fl->width--;
				fl->ret = fl->ret + 1;
			}
			ft_putchar('0');
			fl->ret = fl->ret + 1;
		}
		return (1);
	}
	return (0);
}
