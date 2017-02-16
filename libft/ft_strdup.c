/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:42:11 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/24 20:45:03 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = ft_strlen((char*)s1);
	if ((res = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = s1[i];
	return (res);
}
