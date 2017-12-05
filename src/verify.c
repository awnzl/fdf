/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:26:10 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/14 14:03:35 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check(t_peak *list, double *lim, int size)
{
	double	tmpx;
	double	tmpy;

	while (list)
	{
		tmpx = list->x;
		tmpy = list->y;
		list = list->next;
		if (!list || list->y != tmpy)
			if (tmpx != size)
				return (0);
	}
	lim[0] = tmpx + 1;
	lim[1] = tmpy + 1;
	return (1);
}

void	reset_center(double width, t_peak *peaks)
{
	double	heigth;
	t_peak	*tmp;

	tmp = peaks;
	while (tmp->next)
		tmp = tmp->next;
	heigth = tmp->y;
	while (peaks)
	{
		peaks->x = peaks->x - width / 2;
		peaks->y = peaks->y - heigth / 2;
		peaks = peaks->next;
	}
}

int		verify(t_peak *peaks, double *lim)
{
	int		first;
	t_peak	*tmp;

	first = -1;
	tmp = peaks;
	while (tmp)
	{
		if (tmp->y != 0)
			break ;
		first = tmp->x;
		tmp = tmp->next;
	}
	if (!check(peaks, lim, first))
		return (0);
	reset_center(first, peaks);
	return (1);
}
