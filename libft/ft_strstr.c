/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:37:44 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/26 20:07:03 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0')
		return ((char*)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
			while (to_find[j])
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
				if (to_find[j] == '\0')
					return ((char*)(str + i));
			}
		i++;
	}
	return (NULL);
}
