/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:04 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/27 14:56:08 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if ((s = (char*)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	while (size)
		s[size--] = 0;
	s[0] = 0;
	return (s);
}
