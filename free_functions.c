/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_peak.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:19:54 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/14 16:44:26 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_t_peak(t_peak *p)
{
	t_peak	*tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

void	free_xy(t_isc **xy, double *lim)
{
	int	i;

	i = -1;
	while (++i < lim[1])
		free(xy[i]);
}
