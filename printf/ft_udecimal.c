/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:37:01 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:37:02 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_for_udm(t_fl *fl, size_t num, size_t len)
{
	char	*str;

	while (fl->accur > (int)len)
	{
		ft_putchar('0');
		len++;
	}
	str = ft_itoa_base(num, 10);
	ft_putstr(str);
	free(str);
	while (fl->width > (int)len)
	{
		ft_putchar(' ');
		len++;
	}
	fl->ret = fl->ret + (int)len;
}

void	ft_for_udp(t_fl *fl, size_t num, size_t len)
{
	char	*str;

	if (fl->accur > 0)
		fl->zero = 0;
	while ((fl->width > fl->accur) && (fl->width > (int)len))
	{
		if (fl->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		fl->width--;
		fl->ret = fl->ret + 1;
	}
	while (fl->accur > (int)len)
	{
		ft_putchar('0');
		fl->accur--;
		fl->ret = fl->ret + 1;
	}
	str = ft_itoa_base(num, 10);
	ft_putstr(str);
	free(str);
	fl->ret = fl->ret + (int)len;
}

void	ft_ch_flagud(t_fl *fl, size_t *num)
{
	if (fl->len == 'j')
		*num = (uintmax_t)va_arg(fl->arg, uintmax_t);
	else if (fl->len == 'z')
		*num = (size_t)va_arg(fl->arg, size_t);
	else if (fl->len == 'h' && fl->type == 'U')
		*num = (unsigned long int)va_arg(fl->arg, unsigned long int);
	else if (fl->len == 'h' && fl->s_len == 1)
		*num = (unsigned short int)va_arg(fl->arg, int);
	else if (fl->len == 'h' && fl->s_len == 2)
		*num = (unsigned char)va_arg(fl->arg, int);
	else if ((fl->len == 'l' && fl->s_len == 1) || fl->type == 'U')
		*num = (unsigned long int)va_arg(fl->arg, unsigned long int);
	else if (fl->len == 'l' && fl->s_len == 2)
		*num = (unsigned long long int)va_arg(fl->arg, unsigned long long int);
	else
		*num = (unsigned int)va_arg(fl->arg, unsigned int);
}

void	ft_udecimal(t_fl *fl)
{
	size_t num;
	size_t len;

	ft_ch_flagud(fl, &num);
	len = ft_unumlen(num);
	if (fl->minus == 1)
	{
		if (ft_pr_argu(num, fl))
			return ;
		ft_for_udm(fl, num, len);
	}
	else
	{
		if (ft_pr_argu(num, fl))
			return ;
		ft_for_udp(fl, num, len);
	}
}
