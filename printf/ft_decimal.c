/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:30:05 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:30:08 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkd(t_fl *fl, intmax_t num, size_t *len)
{
	if (fl->plus == 1 && num < 0)
		fl->plus = 0;
	if (fl->space == 1 && (num < 0 || fl->plus == 1))
		fl->space = 0;
	if (fl->accur > (int)(*len) && fl->space == 1)
		fl->space = 0;
	if (fl->plus == 1 || fl->space == 1)
	{
		fl->width--;
		fl->ret = fl->ret + 1;
	}
	if (fl->accur > 0 && fl->zero == 1)
		fl->zero = 0;
	if (fl->accur >= (int)(*len) && num < 0)
	{
		(*len)--;
		fl->width--;
		fl->ret = fl->ret + 1;
	}
}

void	ft_pr_dm(size_t *len, t_fl *fl, intmax_t num)
{
	char *str;

	if (fl->plus == 1)
		ft_putchar('+');
	if (fl->space == 1)
		ft_putchar(' ');
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	str = ft_itoa_basem(num, 10);
	ft_putstr(str);
	free(str);
	while (fl->width > (int)(*len))
	{
		ft_putchar(' ');
		(*len)++;
	}
	fl->ret = fl->ret + (*len);
}

void	ft_pr_dp(size_t *len, t_fl *fl, intmax_t num)
{
	if (fl->accur > (int)(*len) && fl->width >= fl->accur)
		ft_dp1(fl, num);
	else if (fl->accur > (int)(*len) && fl->width < fl->accur)
		ft_dp2(len, fl, num);
	else
		ft_dp3(len, fl, num);
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_dp4(num);
	fl->ret = fl->ret + (*len);
}

void	ft_ch_flag(t_fl *fl, intmax_t *num)
{
	if (fl->len == 'j')
		*num = (intmax_t)va_arg(fl->arg, intmax_t);
	else if (fl->len == 'z')
		*num = (size_t)va_arg(fl->arg, size_t);
	else if (fl->len == 'h' && fl->type == 'D')
		*num = (long int)va_arg(fl->arg, long int);
	else if (fl->len == 'h' && fl->s_len == 1)
		*num = (short int)va_arg(fl->arg, int);
	else if (fl->len == 'h' && fl->s_len == 2)
		*num = (signed char)va_arg(fl->arg, int);
	else if ((fl->len == 'l' && fl->s_len == 1) || fl->type == 'D')
		*num = (long int)va_arg(fl->arg, long int);
	else if (fl->len == 'l' && fl->s_len == 2)
		*num = (long long int)va_arg(fl->arg, long long int);
	else
		*num = va_arg(fl->arg, int);
}

void	ft_decimal(t_fl *fl)
{
	intmax_t	num;
	size_t		len;

	ft_ch_flag(fl, &num);
	len = ft_numlend(num);
	ft_checkd(fl, num, &len);
	if (fl->minus == 1)
	{
		if (ft_pr_argz(len, num, fl))
			return ;
		ft_pr_dm(&len, fl, num);
	}
	else
	{
		if (ft_pr_argz(len, num, fl))
			return ;
		ft_pr_dp(&len, fl, num);
	}
}
