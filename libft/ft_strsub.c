/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:49:29 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 17:49:29 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (s)
	{
		if ((str = (char*)malloc(sizeof(char) * len + 1)) == 0)
			return (NULL);
		i = -1;
		while (++i < len)
			str[i] = s[start++];
		str[i] = 0;
	}
	return (str);
}
