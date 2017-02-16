/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:06:24 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/24 18:42:29 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	s1u = (unsigned char*)s1;
	s2u = (unsigned char*)s2;
	i = -1;
	while (++i < n)
	{
		if (s1u[i] != s2u[i])
			return (s1u[i] - s2u[i]);
	}
	return (0);
}
