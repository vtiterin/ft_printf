/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:31:13 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:31:16 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dp1(t_fl *fl, intmax_t num)
{
	if (fl->zero == 1)
	{
		ft_pr_symb(num, fl);
		while (fl->width > fl->accur)
		{
			ft_putchar('0');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
	}
	else
	{
		while (fl->width > fl->accur)
		{
			ft_putchar(' ');
			fl->ret = fl->ret + 1;
			fl->width--;
		}
		ft_pr_symb(num, fl);
	}
}

void	ft_dp2(size_t *len, t_fl *fl, intmax_t num)
{
	if (fl->zero == 1)
	{
		ft_pr_symb(num, fl);
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
		ft_pr_symb(num, fl);
	}
}

void	ft_dp3(size_t *len, t_fl *fl, intmax_t num)
{
	if (fl->zero == 1)
	{
		ft_pr_symb(num, fl);
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
		ft_pr_symb(num, fl);
	}
}

void	ft_dp4(intmax_t num)
{
	char *str;

	if (num < 0)
	{
		str = ft_itoa_basem(num, 10);
		ft_putstr(&str[1]);
		free(str);
	}
	else
	{
		str = ft_itoa_basem(num, 10);
		ft_putstr(str);
		free(str);
	}
}
