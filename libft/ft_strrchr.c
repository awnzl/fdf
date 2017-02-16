/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:15:42 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 18:07:03 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	uc;
	int		i;

	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	uc = (char)c;
	i = ft_strlen(s) - 1;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}
