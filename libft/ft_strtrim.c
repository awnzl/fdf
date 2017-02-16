/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:03:16 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/30 17:50:24 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		k;
	int		j;

	str = NULL;
	if (s)
	{
		i = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		k = ft_strlen(s) - 1;
		while (s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
			k--;
		k++;
		if (k - i < 0)
			str = (char*)malloc(sizeof(char) * (1));
		else if ((str = (char*)malloc(sizeof(char) * (k - i + 1))) == 0)
			return (NULL);
		j = -1;
		while (i < k)
			str[++j] = s[i++];
		str[++j] = 0;
	}
	return (str);
}
