/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:16:20 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 16:19:13 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pix(int x, int y, int col, t_win *win)
{
	int		r;
	int		p;

	p = round_n(x) + round_n(y) * win->width;
	if (p > -1 && p < win->width * win->height)
	{
		r = win->width + round_n(y) * win->width;
		if (p < r && p > r - win->width - 1)
			win->imdat[p] = col;
	}
}

int		get_pix_color(t_isc *s, t_isc *e, int step, int steps)
{
	int				sc[3];
	int				ec[3];
	int				col[3];
	unsigned int	scol;
	unsigned int	ecol;

	if (steps == 0 || s->color == e->color)
		return (s->color);
	scol = s->color;
	ecol = e->color;
	sc[0] = scol >> 16;
	sc[1] = (scol & 0x00FF00) >> 8;
	sc[2] = (scol & 0x0000FF);
	ec[0] = ecol >> 16;
	ec[1] = (ecol & 0x00FF00) >> 8;
	ec[2] = (ecol & 0x0000FF);
	col[0] = ABS(step * ((sc[0] - ec[0]) / steps) + sc[0]);
	col[1] = ABS(step * ((sc[1] - ec[1]) / steps) + sc[1]);
	col[2] = ABS(step * ((sc[2] - ec[2]) / steps) + sc[2]);
	return ((col[0] << 16) | (col[1] << 8) | (col[2]));
}

void	draw_line(t_isc *s, t_isc *e, t_win *win)
{
	double	temp[2];
	int		i;

	temp[0] = s->x;
	i = -1;
	while ((int)temp[0] != (int)e->x)
	{
		if (!(e->x - s->x))
			continue ;
		temp[1] = (temp[0] - s->x) * (e->y - s->y) / (e->x - s->x) + s->y;
		put_pix(temp[0], temp[1], (win->gr == 0 ? s->color :
					get_pix_color(s, e, ++i, (s->x - e->x))), win);
		temp[0] += (s->x < e->x) ? 1 : -1;
	}
	temp[1] = s->y;
	i = -1;
	while ((int)temp[1] != (int)e->y)
	{
		if (!(e->y - s->y))
			continue ;
		temp[0] = (temp[1] - s->y) * (e->x - s->x) / (e->y - s->y) + s->x;
		put_pix(temp[0], temp[1], (win->gr == 0 ? s->color :
					get_pix_color(s, e, ++i, (s->y - e->y))), win);
		temp[1] += (s->y < e->y) ? 1 : -1;
	}
}
