/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:31:53 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/26 20:04:04 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;
	size_t			i;

	us = (unsigned char*)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (us[i] == uc)
			return (us + i);
		i++;
	}
	return (NULL);
}
