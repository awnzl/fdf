/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:25:20 by avenzel           #+#    #+#             */
/*   Updated: 2017/01/31 16:05:30 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int znak;
	int znak_value;
	int n;
	int i;

	i = -1;
	znak = 0;
	znak_value = 1;
	n = 0;
	while ((s[++i] >= '0' && s[i] <= '9') || ((s[i] == ' ' || s[i] == '\n'
				|| s[i] == '\r' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f'
				|| s[i] == '-' || s[i] == '+') && !znak))
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\r' || s[i] == '\t'
					|| s[i] == '\v' || s[i] == '\f')
			continue ;
		if (s[i] == '-')
			znak_value = -1;
		if ((s[i] >= '1' && s[i] <= '9') || (s[i] == '0' && znak))
			n = n * 10 + (s[i] - 48);
		znak = 1;
	}
	return (n * znak_value);
}
