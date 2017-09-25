/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:35:09 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:35:11 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkxx(t_fl *fl, intmax_t num)
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

void	ft_pr_hexxm(size_t *len, t_fl *fl, char *str)
{
	if (fl->grid == 1)
		ft_putstr("0x");
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

void	ft_pr_hexxp(size_t *len, t_fl *fl, intmax_t num, char *str)
{
	if (fl->accur > (int)(*len) && fl->width > fl->accur)
		ft_hexxp1(fl, num);
	else if (fl->accur > (int)(*len) && fl->width < fl->accur)
		ft_hexxp2(len, fl);
	else
		ft_hexxp3(len, fl);
	while (fl->accur > (int)(*len))
	{
		ft_putchar('0');
		(*len)++;
	}
	ft_puthex(str);
	fl->ret = fl->ret + (*len);
}

void	ft_ch_flagxx(t_fl *fl, intmax_t *num)
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

void	ft_hexadx(t_fl *fl)
{
	intmax_t	num;
	size_t		len;
	char		*str;

	ft_ch_flagxx(fl, &num);
	str = ft_itoa_base(num, 16);
	len = ft_strlen(str);
	ft_checkxx(fl, num);
	if (fl->minus == 1)
	{
		if (ft_pr_argxx(num, fl))
			return ;
		ft_pr_hexxm(&len, fl, str);
	}
	else
	{
		if (ft_pr_argxx(num, fl))
			return ;
		ft_pr_hexxp(&len, fl, num, str);
	}
	free(str);
}
