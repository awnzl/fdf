/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:41:45 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 17:47:15 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	str = NULL;
	if (s1 && s2)
	{
		if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))) == 0)
			return (NULL);
		i = -1;
		while (*s1)
			str[++i] = *(s1++);
		while (*s2)
			str[++i] = *(s2++);
		str[++i] = 0;
	}
	return (str);
}
