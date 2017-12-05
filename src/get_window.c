/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:02:38 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 16:51:09 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xy_arr_init(t_isc **xy, double *lim)
{
	int		i;

	i = -1;
	while (++i < lim[1])
		xy[i] = (t_isc*)malloc(sizeof(t_isc) * lim[0]);
}

void	get_win_size(t_win *win, double *lim)
{
	win->width = 1000;
	win->height = 800;
	win->xy = (t_isc**)malloc(sizeof(t_isc*) * lim[1]);
	win->multp = win->height / lim[0];
	xy_arr_init(win->xy, lim);
}

int		get_window(double *lim, t_win **window, char *map_name)
{
	t_win	*win;

	if ((win = (t_win*)malloc(sizeof(t_win))) == 0)
		return (0);
	get_win_size(win, lim);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, map_name);
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->img_data = (unsigned char*)mlx_get_data_addr(win->img,
			&(win->bspp), &(win->linesize), &(win->endian));
	win->imdat = (int*)(win->img_data);
	win->lim = lim;
	win->ang = 8;
	win->xmove = 0;
	win->ymove = 0;
	win->a = 48.5;
	win->b = 0;
	win->g = 315;
	win->pks = 0;
	win->gr = 0;
	*window = win;
	return (1);
}
