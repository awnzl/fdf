/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:14:28 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/14 18:58:12 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ox(t_peak *pk, double a)
{
	double y;
	double z;

	RADIAN(a);
	y = pk->y;
	z = -pk->z;
	pk->y = y * cos(a) + z * sin(a);
	pk->z = z * cos(a) - y * sin(a);
}

void	oy(t_peak *pk, double b)
{
	double x;
	double z;

	RADIAN(b);
	x = pk->x;
	z = -pk->z;
	pk->x = x * cos(b) - z * sin(b);
	pk->z = z * cos(b) + x * sin(b);
}

void	oz(t_peak *pk, double g)
{
	double x;
	double y;

	RADIAN(g);
	x = pk->x;
	y = pk->y;
	pk->x = x * cos(g) + y * sin(g);
	pk->y = y * cos(g) - x * sin(g);
}

void	rotate(t_peak *pk, t_peak *rt, t_win *win)
{
	rt->x = pk->x;
	rt->y = pk->y;
	rt->z = pk->z;
	oz(rt, win->g);
	ox(rt, win->a);
	oy(rt, win->b);
}

void	fillxy(t_peak *pk, t_win *win)
{
	int		i;
	int		j;
	int		xmv;
	int		ymv;
	t_peak	rt;

	xmv = win->width / 2 + win->xmove;
	ymv = win->height / 2 + win->ymove;
	i = 0;
	j = 0;
	while (pk)
	{
		rotate(pk, &rt, win);
		win->xy[i][j].x = rt.x * win->multp + xmv;
		win->xy[i][j].y = rt.y * win->multp + ymv;
		win->xy[i][j++].color = pk->color;
		if (j == win->lim[0])
		{
			j = 0;
			i++;
		}
		pk = pk->next;
	}
}
