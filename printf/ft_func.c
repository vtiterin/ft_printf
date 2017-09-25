/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:34:27 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:34:31 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux(size_t n, size_t b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

char	*ft_itoa_base(size_t value, size_t base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = ft_strnew(65)))
		return (NULL);
	p = 0;
	aux(value, base, ans, &p);
	return (ans);
}

void	ft_puthex(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		ft_putchar(ft_tolower(str[i]));
		i++;
	}
}

size_t	ft_numlend(intmax_t n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}
