/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:29:52 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 17:48:38 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = NULL;
	if (s)
	{
		if ((str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == 0)
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = 0;
	}
	return (str);
}
