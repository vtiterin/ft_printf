/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foct1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:32:37 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:32:40 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ch_flago(t_fl *fl, intmax_t *num)
{
	if (fl->len == 'j')
		*num = (uintmax_t)va_arg(fl->arg, uintmax_t);
	else if (fl->len == 'z')
		*num = (size_t)va_arg(fl->arg, size_t);
	else if (fl->len == 'h' && fl->type == 'O')
		*num = (unsigned long int)va_arg(fl->arg, unsigned long int);
	else if (fl->len == 'h' && fl->s_len == 1)
		*num = (unsigned short int)va_arg(fl->arg, int);
	else if (fl->len == 'h' && fl->s_len == 2)
		*num = (unsigned char)va_arg(fl->arg, int);
	else if ((fl->len == 'l' && fl->s_len == 1) || fl->type == 'O')
		*num = (unsigned long int)va_arg(fl->arg, unsigned long int);
	else if (fl->len == 'l' && fl->s_len == 2)
		*num = (unsigned long long int)va_arg(fl->arg, unsigned long long int);
	else
		*num = (unsigned int)va_arg(fl->arg, unsigned int);
}
