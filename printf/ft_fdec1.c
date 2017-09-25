/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdec1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:30:32 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:30:36 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pr_argp(intmax_t num, t_fl *fl)
{
	int		i;
	char	*str;

	if (fl->plus == 1)
		ft_putchar('+');
	if (fl->space == 1)
	{
		ft_putchar(' ');
	}
	str = ft_itoa_basem(num, 10);
	i = ft_strlen(str);
	ft_putstr(str);
	fl->ret = fl->ret + i;
	free(str);
	while (i < (fl->width))
	{
		ft_putchar(' ');
		i++;
		fl->ret = fl->ret + 1;
	}
}

int		ft_pr_argz(size_t len, intmax_t num, t_fl *fl)
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
	else if (fl->t && num > 0)
	{
		if (fl->minus == 1)
			ft_pr_argp(num, fl);
		else
			ft_pr_dp(&len, fl, num);
		return (1);
	}
	return (0);
}

void	ft_pr_symb(intmax_t num, t_fl *fl)
{
	if (fl->plus == 1)
		ft_putchar('+');
	if (fl->space == 1)
		ft_putchar(' ');
	if (num < 0)
		ft_putchar('-');
}
