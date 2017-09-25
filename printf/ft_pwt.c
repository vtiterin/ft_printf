/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:36:34 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:37 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwch3(unsigned int symb, int *i)
{
	unsigned char	byte4;
	unsigned char	byte3;
	unsigned char	byte2;
	unsigned char	byte1;
	unsigned char	octet;

	byte4 = (symb << 26) >> 26;
	byte3 = ((symb >> 6) << 26) >> 26;
	byte2 = ((symb >> 12) << 26) >> 26;
	byte1 = ((symb >> 18) << 29) >> 29;
	octet = ((unsigned int)0xF0808080 >> 24) | byte1;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xF0808080 << 8) >> 24) | byte2;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xF0808080 << 16) >> 24) | byte3;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xF0808080 << 24) >> 24) | byte4;
	*i += write(1, &octet, 1);
}

void	ft_putwch2(unsigned int symb, int *i)
{
	unsigned char	byte3;
	unsigned char	byte2;
	unsigned char	byte1;
	unsigned char	octet;

	byte3 = (symb << 26) >> 26;
	byte2 = ((symb >> 6) << 26) >> 26;
	byte1 = ((symb >> 12) << 28) >> 28;
	octet = ((unsigned int)0xE08080 >> 16) | byte1;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xE08080 << 16) >> 24) | byte2;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xE08080 << 24) >> 24) | byte3;
	*i += write(1, &octet, 1);
}

void	ft_putwch1(unsigned int symb, int *i)
{
	unsigned char	byte2;
	unsigned char	byte1;
	unsigned char	octet;

	byte2 = (symb << 26) >> 26;
	byte1 = ((symb >> 6) << 27) >> 27;
	octet = ((unsigned int)0xC080 >> 8) | byte1;
	*i += write(1, &octet, 1);
	octet = (((unsigned int)0xC080 << 24) >> 24) | byte2;
	*i += write(1, &octet, 1);
}

int		ft_putwch(wchar_t value)
{
	int				i;
	unsigned int	symb;
	unsigned char	octet;
	int				size;
	char			*tmp;

	symb = value;
	tmp = ft_itoa_base(value, 2);
	i = 0;
	size = ft_strlen(tmp);
	free(tmp);
	if (size <= 7)
	{
		octet = value;
		i += write(1, &octet, 1);
	}
	else if (size <= 11)
		ft_putwch1(symb, &i);
	else if (size <= 16)
		ft_putwch2(symb, &i);
	else
		ft_putwch3(symb, &i);
	return (i);
}
