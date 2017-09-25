/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:33:54 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:33:56 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_trim_m(t_fl *fl, char *str, char ch)
{
	char	*tmp;
	size_t	i;

	if ((int)ft_strlen(str) < fl->width)
	{
		i = ft_strlen(str);
		tmp = ft_strnew(fl->width);
		ft_strncpy(tmp, str, i);
		while ((int)i < fl->width)
		{
			tmp[i] = ch;
			i++;
		}
		return (tmp);
	}
	else
	{
		return (str);
	}
}

char	*width_trim_p(t_fl *fl, char *str, char ch)
{
	char	*tmp;
	size_t	i;

	if ((int)ft_strlen(str) < fl->width)
	{
		i = 0;
		tmp = ft_strnew(fl->width);
		while ((int)i < fl->width - (int)ft_strlen(str))
		{
			if (fl->zero == 1)
				tmp[i] = '0';
			else
				tmp[i] = ch;
			i++;
		}
		ft_strcat(tmp, str);
		return (tmp);
	}
	else
	{
		return (str);
	}
}

void	ft_prnstr(t_fl *fl)
{
	if (fl->width != 0)
	{
		while (fl->width)
		{
			ft_putchar('0');
			fl->width--;
			fl->ret = fl->ret + 1;
		}
	}
	else
	{
		ft_putstr("(null)");
		fl->ret = fl->ret + 6;
	}
}

void	ft_str_s(t_fl *fl)
{
	char *str;

	str = va_arg(fl->arg, char *);
	if (str == NULL)
	{
		ft_prnstr(fl);
		return ;
	}
	if (fl->minus == 1)
	{
		if (ft_pr_args(fl))
			return ;
		str = width_trim_m(fl, acur_trim(fl, str), ' ');
		fl->ret = fl->ret + (int)ft_strlen(str);
		ft_putstr(str);
	}
	else
	{
		if (ft_pr_args(fl))
			return ;
		str = width_trim_p(fl, acur_trim(fl, str), ' ');
		fl->ret = fl->ret + (int)ft_strlen(str);
		ft_putstr(str);
	}
}
