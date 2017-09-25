/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:38:24 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:38:26 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_poip1(t_fl *fl, int num)
{
	while (fl->width > (fl->accur + 2) && num >= 0)
	{
		ft_putchar(' ');
		fl->ret = fl->ret + 1;
		fl->width--;
	}
	ft_putstr("0x");
}

void	ft_poip2(size_t *len, t_fl *fl)
{
	while (fl->width > fl->accur - (int)(*len) + 2)
	{
		ft_putchar(' ');
		fl->ret = fl->ret + 1;
		fl->width--;
	}
	ft_putstr("0x");
}

void	ft_poip3(size_t *len, t_fl *fl)
{
	if (fl->zero == 1)
		ft_putstr("0x");
	while (fl->width > (int)(*len) + 2)
	{
		if (fl->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->ret = fl->ret + 1;
		fl->width--;
	}
	if (fl->zero != 1)
		ft_putstr("0x");
}
