/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:47:57 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/16 17:32:45 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	round_n(double nb)
{
	int	n;

	n = (int)nb;
	return ((nb - n) > 0.45 ? (n + 1) : n);
}

int	doit(int fd, char *map_name)
{
	t_peak	*peaks;
	t_win	*window;
	double	limits[2];

	if (!get_data(fd, &peaks) || !verify(peaks, limits))
		return (0);
	if (!get_window(limits, &window, map_name))
		return (0);
	let_the_window_begin(window, peaks);
	free(window);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		ft_putendl("usage: ./fdf fdf_map_name\n");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (1);
	if (!doit(fd, av[1]))
		ft_putendl("error");
	return (0);
}
