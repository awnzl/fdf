/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:21:43 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 16:20:00 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_peaks(t_win *win)
{
	int		i;
	int		j;

	i = -1;
	while (++i < win->lim[1])
	{
		j = -1;
		while (++j < win->lim[0])
			put_pix(win->xy[i][j].x, win->xy[i][j].y, win->xy[i][j].color, win);
	}
	if (win->lim[0] == 1 && win->lim[1] == 1)
		put_pix(win->xy[0][0].x, win->xy[0][0].y, win->xy[0][0].color, win);
}

void	draw_img(t_win *win)
{
	int		i;
	int		j;

	i = -1;
	while (++i < win->lim[1])
	{
		j = -1;
		while (++j < win->lim[0])
		{
			if (j + 1 < win->lim[0])
				draw_line(&win->xy[i][j], &win->xy[i][j + 1], win);
			if (i + 1 < win->lim[1])
				draw_line(&win->xy[i][j], &win->xy[i + 1][j], win);
		}
	}
	if (win->lim[0] == 1 && win->lim[1] == 1)
		put_pix(win->xy[0][0].x, win->xy[0][0].y, win->xy[0][0].color, win);
}

void	get_image_content(t_win *win, t_peak *peaks)
{
	int		i;
	int		j;

	fillxy(peaks, win);
	if (win->pks)
	{
		draw_peaks(win);
		return ;
	}
	i = -1;
	while (++i < win->lim[1])
	{
		j = -1;
		while (++j < win->lim[0])
		{
			if (j + 1 < win->lim[0])
				draw_line(&win->xy[i][j], &win->xy[i][j + 1], win);
			if (i + 1 < win->lim[1])
				draw_line(&win->xy[i][j], &win->xy[i + 1][j], win);
		}
	}
	if (win->lim[0] == 1 && win->lim[1] == 1)
		put_pix(win->xy[0][0].x, win->xy[0][0].y, win->xy[0][0].color, win);
}
