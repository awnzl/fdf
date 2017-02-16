/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:05:25 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/26 20:53:15 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[j] && (i + 1) < size)
		s1[i++] = s2[j++];
	s1[i] = 0;
	if (!j)
		i = size;
	while (s2[j++])
		i++;
	return (i);
}
