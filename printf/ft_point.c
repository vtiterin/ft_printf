/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:33:26 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:33:29 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pr_argpp(int num, t_fl *fl)
{
	if (fl->t && num == 0)
	{
		ft_putstr("0x");
		fl->ret = fl->ret + 2;
		while (fl->accur)
		{
			ft_putchar('0');
			fl->accur--;
			fl->ret = fl->ret + 1;
		}
		return (1);
	}
	return (0);
}

void	ft_pr_pm(t_fl *fl, size_t len, char *str)
{
	ft_putstr("0x");
	while (fl->accur > (int)(len))
	{
		ft_putchar('0');
		(len)++;
	}
	ft_puthex(str);
	len = len + 2;
	while (fl->width > (int)(len))
	{
		ft_putchar(' ');
		(len)++;
	}
	fl->ret = fl->ret + (len);
}

void	ft_pr_pp(size_t *len, t_fl *fl, int num, char *str)
{
	if (fl->accur > (int)(*len) && fl->width > fl->accur)
		ft_poip1(fl, num);
	else if (fl->accur > (int)(*len) && fl->width < fl->accur)
		ft_poip2(len, fl);
	else
		ft_poip3(len, fl);
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		fl->accur--;
		fl->ret = fl->ret + 1;
	}
	ft_puthex(str);
	fl->ret = fl->ret + (*len) + 2;
}

void	ft_point(t_fl *fl)
{
	char	*str;
	size_t	i;
	size_t	num;

	num = (size_t)va_arg(fl->arg, void *);
	str = ft_itoa_base(num, 16);
	if (fl->minus == 1)
	{
		if (ft_pr_argpp(num, fl))
			return ;
		i = ft_strlen(str);
		ft_pr_pm(fl, i, str);
	}
	else
	{
		if (ft_pr_argpp(num, fl))
			return ;
		i = ft_strlen(str);
		ft_pr_pp(&i, fl, num, str);
	}
	free(str);
}
