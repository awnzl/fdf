/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:48:16 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 16:51:16 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>

# define RADIAN(a) (a = 0.01745329 * a)
# define ABS(a) (a < 0) ? -(a) : (a)

typedef struct		s_isc
{
	double			x;
	double			y;
	unsigned int	color;
}					t_isc;

typedef struct		s_peak
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	struct s_peak	*next;
}					t_peak;

typedef struct		s_win
{
	t_isc			**xy;
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*img_data;
	int				*imdat;
	int				bspp;
	int				linesize;
	int				endian;
	int				width;
	int				height;
	int				xmove;
	int				ymove;
	int				pks;
	int				gr;
	double			*lim;
	double			ang;
	double			multp;
	double			a;
	double			b;
	double			g;
}					t_win;

typedef struct		s_cont
{
	t_win			*w;
	t_peak			*p;
}					t_cont;

int					get_data(int fd, t_peak **peaks);
int					verify(t_peak *peaks, double *lim);
int					get_window(double *l, t_win **w, char *name);
int					let_the_window_begin(t_win *win, t_peak *peaks);
int					round_n(double nb);
void				get_image_content(t_win *w, t_peak *p);
void				free_t_peak(t_peak *p);
void				free_xy(t_isc **xy, double *lim);
void				draw_image(t_win *win);
void				draw_line(t_isc *s, t_isc *e, t_win *win);
void				put_pix(int x, int y, int col, t_win *win);
void				fillxy(t_peak *pk, t_win *win);
void				check_key(int kc, t_cont *conteiner);

#endif
