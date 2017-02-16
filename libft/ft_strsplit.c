/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:40:18 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/29 19:09:23 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		end;
	int		count;

	if (!s)
		return (NULL);
	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
	if ((arr = (char**)malloc(sizeof(char*) * count + 1)) == 0)
		return (NULL);
	arr[count--] = NULL;
	end = i;
	while (i--)
	{
		if (s[i] != c && s[i + 1] == c)
			end = i;
		if (s[i] != c && (s[i - 1] == c || i == 0))
			if ((arr[count--] = ft_strsub(s, i, end - i + 1)) == 0)
				return (NULL);
	}
	return (arr);
}
