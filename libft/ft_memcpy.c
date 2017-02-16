/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:04:24 by avenzel           #+#    #+#             */
/*   Updated: 2016/12/03 12:19:05 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *usrc;
	unsigned char *udst;

	usrc = (unsigned char*)src;
	udst = (unsigned char*)dst;
	while (n--)
		udst[n] = usrc[n];
	return (udst);
}
