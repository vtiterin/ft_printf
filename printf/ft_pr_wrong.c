/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_wrong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:35:59 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:01 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wr_wrm(t_fl *fl, char *str)
{
	while (fl->width > 1)
	{
		if (fl->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->width--;
		fl->ret += 1;
	}
	ft_putchar(str[fl->i]);
	fl->ret += 1;
	fl->i++;
}

void	ft_wr_wrong(t_fl *fl, char *str)
{
	if (fl->minus == 0)
	{
		ft_wr_wrm(fl, str);
	}
	else
	{
		ft_putchar(str[fl->i]);
		fl->ret += 1;
		while (fl->width > 1)
		{
			if (fl->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			fl->width--;
			fl->ret += 1;
		}
		fl->i++;
	}
}
