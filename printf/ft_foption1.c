/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foption1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:32:56 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:32:58 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len1(char *str, t_fl *fl, char ch)
{
	if (str[fl->i + 1] == ch)
	{
		if (fl->len == '0')
			fl->len = ch;
		fl->s_len = 0 + 2;
		fl->i = fl->i + fl->s_len;
	}
	else
	{
		if (fl->len == '0')
			fl->len = ch;
		fl->s_len = 0 + 1;
		fl->i = fl->i + fl->s_len;
	}
}

int		ft_len(char *str, t_fl *fl)
{
	if (str[fl->i])
	{
		if (str[fl->i] == 'j')
		{
			ft_len1(str, fl, 'j');
			return (1);
		}
		else if (str[fl->i] == 'z')
		{
			ft_len1(str, fl, 'z');
			return (1);
		}
		else if (str[fl->i] == 'h')
		{
			ft_len1(str, fl, 'h');
			return (1);
		}
		else if (str[fl->i] == 'l')
		{
			ft_len1(str, fl, 'l');
			return (1);
		}
	}
	return (0);
}
