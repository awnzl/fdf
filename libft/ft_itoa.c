/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:02:27 by avenzel           #+#    #+#             */
/*   Updated: 2016/11/28 15:31:40 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		tmp[2];

	tmp[0] = n;
	tmp[1] = 0;
	while (tmp[0] /= 10)
		tmp[1]++;
	if (n < 0)
		tmp[1]++;
	if ((s = (char*)malloc(sizeof(char) * tmp[1] + 2)) == 0)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	s[tmp[1] + 1] = '\0';
	if (n == 0)
		s[tmp[1]--] = '0';
	while (n)
	{
		if (n < 0)
			s[tmp[1]--] = (-(n % 10)) + 48;
		else
			s[tmp[1]--] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
