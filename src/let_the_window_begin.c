/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_window_begin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:02:21 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 16:52:37 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_image(t_win *win, t_peak *peaks)
{
	get_image_content(win, peaks);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->img_data = (unsigned char*)mlx_get_data_addr(win->img,
			&(win->bspp), &(win->linesize), &(win->endian));
	win->imdat = (int*)win->img_data;
}

int		key_hook(int keycode, t_cont *cont)
{
	check_key(keycode, cont);
	if (keycode == 34)
	{
		cont->w->a = 48.5;
		cont->w->b = 0;
		cont->w->g = 315;
	}
	else if (keycode == 87)
	{
		cont->w->xmove = 0;
		cont->w->ymove = 0;
	}
	put_image(cont->w, cont->p);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_cont *cont)
{
	if (x > 0 && y > 0)
	{
		if (button == 4)
			cont->w->multp = (cont->w->multp < cont->w->width) ?
				cont->w->multp += 0.5 : cont->w->width;
		else if (button == 5)
			(cont->w->multp > 0) ? (cont->w->multp -= 0.5) : 0;
	}
	put_image(cont->w, cont->p);
	return (0);
}

int		let_the_window_begin(t_win *win, t_peak *peaks)
{
	t_cont	cont;

	cont.w = win;
	cont.p = peaks;
	put_image(win, peaks);
	mlx_key_hook(win->win, key_hook, (void*)(&cont));
	mlx_mouse_hook(win->win, mouse_hook, (void*)(&cont));
	mlx_loop(win->mlx);
	mlx_destroy_window(win->mlx, win->win);
	return (0);
}
