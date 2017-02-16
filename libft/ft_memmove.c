/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:40:15 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 17:45:40 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *us;
	unsigned char *ud;

	us = (unsigned char*)src;
	ud = (unsigned char*)dst;
	if (dst != src)
	{
		if (dst > src)
			while (len--)
				ud[len] = us[len];
		else
			while (len--)
				*ud++ = *us++;
	}
	return (dst);
}
