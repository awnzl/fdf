/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:31:17 by avenzel           #+#    #+#             */
/*   Updated: 2016/12/08 21:34:25 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *result;

	result = (void*)malloc(size);
	if (result)
	{
		while (size)
			*(result + (--size)) = 0;
		return (result);
	}
	return (NULL);
}
