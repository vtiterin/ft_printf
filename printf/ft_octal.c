/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:35:22 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:35:24 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checko(t_fl *fl, intmax_t num)
{
	if (fl->grid == 1 && num != 0)
	{
		fl->width--;
		fl->ret = fl->ret + 1;
	}
	if (fl->accur > 0 && fl->zero == 1)
		fl->zero = 0;
}

void	ft_pr_octm(size_t *len, t_fl *fl, char *str)
{
	if (fl->grid == 1)
		ft_putstr("0");
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_puthex(str);
	while (fl->width > (int)(*len))
	{
		ft_putchar(' ');
		(*len)++;
	}
	fl->ret = fl->ret + (*len);
}

void	ft_pr_octp(size_t *len, t_fl *fl, intmax_t num, char *str)
{
	if (fl->accur > (int)(*len) && fl->width > fl->accur)
		ft_octp1(fl, num);
	else if (fl->accur > (int)(*len) && fl->width < fl->accur)
		ft_octp2(len, fl);
	else
		ft_octp3(len, fl);
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_puthex(str);
	fl->ret = fl->ret + (*len);
}

int		ft_pros(t_fl *fl)
{
	while (fl->width)
	{
		ft_putchar(' ');
		fl->width--;
		fl->ret = fl->ret + 1;
	}
	ft_putchar('0');
	fl->ret = fl->ret + 1;
	return (1);
}

void	ft_octal(t_fl *fl)
{
	intmax_t	num;
	size_t		len;
	char		*str;

	ft_ch_flago(fl, &num);
	str = ft_itoa_base(num, 8);
	len = ft_strlen(str);
	ft_checko(fl, num);
	if (fl->minus == 1)
	{
		if (ft_pr_argo(fl, num))
			return ;
		else if (num == 0 && ft_pros(fl))
			return ;
		ft_pr_octm(&len, fl, str);
	}
	else
	{
		if (ft_pr_argo(fl, num))
			return ;
		else if (num == 0 && ft_pros(fl))
			return ;
		ft_pr_octp(&len, fl, num, str);
	}
	free(str);
}
