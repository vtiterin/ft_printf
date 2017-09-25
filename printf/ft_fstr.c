/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:33:42 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:33:44 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pr_args(t_fl *fl)
{
	if (fl->t)
	{
		while (fl->width)
		{
			if (fl->zero > 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			fl->width--;
			fl->ret = fl->ret + 1;
		}
		return (1);
	}
	return (0);
}

char	*acur_trim(t_fl *fl, char *str)
{
	char	*tmp;

	if ((int)ft_strlen(str) > fl->accur && fl->accur > 0)
	{
		tmp = ft_strnew(fl->accur);
		ft_strncpy(tmp, str, fl->accur);
		return (tmp);
	}
	else
	{
		return (str);
	}
}
