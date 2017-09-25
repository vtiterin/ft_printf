/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fudecimal1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:34:08 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:34:15 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pr_argu(size_t num, t_fl *fl)
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
	return (0);
}

size_t	ft_unumlen(size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}
