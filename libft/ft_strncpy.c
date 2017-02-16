/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:03:02 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/25 21:35:15 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	size_t			sl;

	if (len > 0)
	{
		sl = ft_strlen(src);
		i = -1;
		while (++i < len)
			if (i < sl)
				dst[i] = src[i];
			else
				dst[i] = '\0';
	}
	return (dst);
}
