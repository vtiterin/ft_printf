/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:33:14 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:33:17 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag1(char *str, t_fl *fl)
{
	while ((str[fl->i] == '+' || str[fl->i] == '-' || str[fl->i] == ' ' ||
			str[fl->i] == '0' || str[fl->i] == '#') && str[fl->i] != '\0')
	{
		if (str[fl->i] == '+')
			fl->plus = 1;
		if (str[fl->i] == '-')
			fl->minus = 1;
		if (str[fl->i] == ' ')
			fl->space = 1;
		if (str[fl->i] == '0')
			fl->zero = 1;
		if (str[fl->i] == '#')
			fl->grid = 1;
		fl->i = fl->i + 1;
	}
	if (fl->minus != 0 && fl->zero != 0)
		fl->zero = 0;
	if (fl->plus != 0 && fl->space != 0)
		fl->space = 0;
}

int		ft_flag(char *str, t_fl *fl)
{
	if ((str[fl->i] == '+' || str[fl->i] == '-' || str[fl->i] == ' ' ||
		str[fl->i] == '0' || str[fl->i] == '#') && str[fl->i] != '\0')
	{
		ft_flag1(str, fl);
		return (1);
	}
	else
		return (0);
}

int		ft_width(char *str, t_fl *fl)
{
	if (str[fl->i])
	{
		if (ft_isdigit(str[fl->i]))
		{
			fl->width = ft_atoi(&str[fl->i]);
			fl->i = fl->i + ft_intlen(fl->width);
			return (1);
		}
	}
	return (0);
}

int		ft_accuracy(char *str, t_fl *fl)
{
	if (str[fl->i])
	{
		if (str[fl->i] == '.')
		{
			if (!(ft_isdigit(str[fl->i + 1])) || str[fl->i + 1] == '0')
			{
				if (str[fl->i + 1] == '0')
					fl->i = fl->i + 1;
				fl->t = 1;
			}
			else if (ft_isdigit(str[fl->i + 1]))
			{
				fl->i = fl->i + 1;
				fl->accur = ft_atoi(&str[fl->i]);
			}
			fl->i = fl->i + ft_intlen(fl->accur);
			return (1);
		}
	}
	return (0);
}

int		ft_type(char *str, t_fl *fl)
{
	if (str[fl->i])
	{
		if (str[fl->i] != '\0' && (ft_strchr("sSpdDioOuUxXcC%", str[fl->i])))
		{
			fl->type = str[fl->i];
			fl->i = fl->i + 1;
		}
		else
			ft_wr_wrong(fl, str);
		return (1);
	}
	return (0);
}
