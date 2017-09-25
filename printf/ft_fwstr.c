/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:34:45 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:34:48 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr(wchar_t *value)
{
	int		i;
	int		r;

	r = 0;
	i = 0;
	while (value[i])
	{
		r += ft_putwch(value[i]);
		i++;
	}
	return (r);
}

int		ft_wstrlen(wchar_t *value)
{
	int		r;
	int		i;

	i = 0;
	r = 0;
	while (value[i])
	{
		r += ft_wchlen(value[i]);
		i++;
	}
	return (r);
}
