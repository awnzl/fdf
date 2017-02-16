/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:43:23 by avenzel           #+#    #+#             */
/*   Updated: 2016/12/03 12:18:34 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	*ud;
	unsigned char	uc;
	unsigned long	i;

	us = (unsigned char*)src;
	ud = (unsigned char*)dst;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ud[i] = us[i];
		if (ud[i] == uc)
			return (ud + i + 1);
		i++;
	}
	return (NULL);
}
