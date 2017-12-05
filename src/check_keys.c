/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:46:13 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 17:32:10 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_all(t_peak *pk, t_win *win)
{
	free_t_peak(pk);
	free_xy(win->xy, win->lim);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}

void	check_move(int kc, t_cont *c)
{
	if (kc == 91)
		c->w->ymove -= 20;
	else if (kc == 84)
		c->w->ymove += 20;
	else if (kc == 86)
		c->w->xmove -= 20;
	else if (kc == 88)
		c->w->xmove += 20;
	else if (kc == 31)
		c->w->multp = c->w->height / c->w->lim[0];
	else if (kc == 8)
		c->w->gr = (c->w->gr == 1) ? 0 : 1;
}

void	check_key(int kc, t_cont *c)
{
	if (kc == 35)
		c->w->pks = (c->w->pks == 1) ? 0 : 1;
	else if (kc == 116)
		c->w->ang = (++c->w->ang > 45) ? 45 : c->w->ang;
	else if (kc == 121)
		c->w->ang = (--c->w->ang < 1) ? 1 : c->w->ang;
	else if (kc == 53)
		close_all(c->p, c->w);
	else if (kc == 124)
		c->w->b = ((c->w->b -= c->w->ang) < 0) ? 360 + c->w->b : c->w->b;
	else if (kc == 123)
		c->w->b = ((c->w->b += c->w->ang) > 360) ? c->w->b - 360 : c->w->b;
	else if (kc == 125)
		c->w->a = ((c->w->a -= c->w->ang) < 0) ? 360 + c->w->a : c->w->a;
	else if (kc == 126)
		c->w->a = ((c->w->a += c->w->ang) > 360) ? c->w->a - 360 : c->w->a;
	else if (kc == 30)
		c->w->g = ((c->w->g -= c->w->ang) < 0) ? 360 + c->w->g : c->w->g;
	else if (kc == 33)
		c->w->g = ((c->w->g += c->w->ang) > 360) ? c->w->g - 360 : c->w->g;
	else if (kc == 69 || kc == 78)
		c->w->multp = (kc == 69) ? c->w->multp + 0.5 : c->w->multp - 0.5;
	else
		check_move(kc, c);
}
