/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:59:11 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/24 15:35:44 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int c, size_t len)
{
	unsigned char uc;
	unsigned char *tmp;

	uc = (unsigned char)c;
	tmp = (unsigned char*)arr;
	while (len--)
		tmp[len] = uc;
	return (arr);
}
