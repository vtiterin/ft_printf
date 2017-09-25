/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:00:25 by vtiterin          #+#    #+#             */
/*   Updated: 2016/11/22 09:00:25 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t lenght)
{
	char	*tmp;

	tmp = str;
	while (lenght)
	{
		*tmp = '\0';
		tmp++;
		lenght--;
	}
}