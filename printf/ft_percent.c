/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:35:43 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:35:45 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_for_per(int i)
{
	if (i == 1)
		ft_putchar('0');
	else
		ft_putchar(' ');
}

void	ft_percent(t_fl *fl)
{
	if (fl->minus == 1)
	{
		ft_putchar('%');
		fl->ret = fl->ret + 1;
		while (fl->width > 1)
		{
			ft_for_per(fl->zero);
			fl->width--;
			fl->ret = fl->ret + 1;
		}
	}
	else
	{
		while (fl->width > 1)
		{
			ft_for_per(fl->zero);
			fl->width--;
			fl->ret = fl->ret + 1;
		}
		ft_putchar('%');
		fl->ret = fl->ret + 1;
	}
}
