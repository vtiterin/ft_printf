/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:34:57 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:35:00 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkx(t_fl *fl, intmax_t num)
{
	if (fl->grid == 1 && num != 0)
	{
		fl->width -= 2;
		fl->ret = fl->ret + 2;
	}
	else
		fl->grid = 0;
	if (fl->accur > 0 && fl->zero == 1)
		fl->zero = 0;
}

void	ft_pr_hexm(size_t *len, t_fl *fl, char *str)
{
	if (fl->grid == 1)
		ft_putstr("0X");
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_putstr(str);
	while (fl->width > (int)(*len))
	{
		ft_putchar(' ');
		(*len)++;
	}
	fl->ret = fl->ret + (*len);
}

void	ft_pr_hexp(size_t *len, t_fl *fl, intmax_t num, char *str)
{
	if (fl->accur > (int)(*len) && fl->width > fl->accur)
		ft_hexp1(fl, num);
	else if (fl->accur > (int)(*len) && fl->width < fl->accur)
		ft_hexp2(len, fl);
	else
		ft_hexp3(len, fl);
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_putstr(str);
	fl->ret = fl->ret + (*len);
}

void	ft_ch_flagx(t_fl *fl, intmax_t *num)
{
	if (fl->len == 'j')
		*num = (uintmax_t)va_arg(fl->arg, uintmax_t);
	else if (fl->len == 'z')
		*num = (size_t)va_arg(fl->arg, size_t);
	else if (fl->len == 'h' && fl->s_len == 1)
		*num = (unsigned short int)va_arg(fl->arg, int);
	else if (fl->len == 'h' && fl->s_len == 2)
		*num = (unsigned char)va_arg(fl->arg, int);
	else if (fl->len == 'l' && fl->s_len == 1)
		*num = (unsigned long int)va_arg(fl->arg, unsigned long int);
	else if (fl->len == 'l' && fl->s_len == 2)
		*num = (unsigned long long int)va_arg(fl->arg, unsigned long long int);
	else
		*num = (unsigned int)va_arg(fl->arg, unsigned int);
}

void	ft_hexad(t_fl *fl)
{
	intmax_t	num;
	size_t		len;
	char		*str;

	ft_ch_flagx(fl, &num);
	str = ft_itoa_base(num, 16);
	len = ft_strlen(str);
	ft_checkx(fl, num);
	if (fl->minus == 1)
	{
		if (ft_pr_argx(num, fl))
			return ;
		ft_pr_hexm(&len, fl, str);
	}
	else
	{
		if (ft_pr_argx(num, fl))
			return ;
		ft_pr_hexp(&len, fl, num, str);
	}
	free(str);
}
