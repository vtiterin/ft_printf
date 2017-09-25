/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:36:45 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:48 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_basic_fl(t_fl *fl)
{
	if ((fl->type == 's' && fl->len == 'l') || fl->type == 'S')
		ft_str_ss(fl);
	else if (fl->type == 's')
		ft_str_s(fl);
	else if (fl->type == 'p')
		ft_point(fl);
	else if (fl->type == 'd' || fl->type == 'D' || fl->type == 'i')
		ft_decimal(fl);
	else if (fl->type == 'o' || fl->type == 'O')
		ft_octal(fl);
	else if (fl->type == 'u' || fl->type == 'U')
		ft_udecimal(fl);
	else if (fl->type == 'X')
		ft_hexad(fl);
	else if (fl->type == 'x')
		ft_hexadx(fl);
	else if (fl->type == 'c' || fl->type == 'C')
		ft_char(fl);
	else if (fl->type == '%')
		ft_percent(fl);
}

void	ft_solve(char *str, t_fl *fl)
{
	while ((ft_flag(str, fl) || ft_width(str, fl) || ft_accuracy(str, fl)
			|| ft_len(str, fl)) && str[fl->i] != '\0')
	{
	}
	ft_type(str, fl);
	ft_basic_fl(fl);
}

void	ft_initialization(t_fl *fl)
{
	fl->plus = 0;
	fl->minus = 0;
	fl->space = 0;
	fl->zero = 0;
	fl->grid = 0;
	fl->width = 0;
	fl->accur = 0;
	fl->t = 0;
	fl->type = '0';
	fl->len = '0';
	fl->s_len = 0;
}
