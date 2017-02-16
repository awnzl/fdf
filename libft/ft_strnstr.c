/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:25:31 by avenzel           #+#    #+#             */
/*   Updated: 2016/12/03 15:22:32 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *ret_big;

	ret_big = ft_strstr(big, little);
	if ((ret_big - big) + ft_strlen(little) > len)
		return (0);
	return (ret_big);
}
