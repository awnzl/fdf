/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:48:46 by avenzel           #+#    #+#             */
/*   Updated: 2017/02/15 12:28:53 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 ** функция get_data() инициализирует и заполняет лист, хранящий всю информацию
 ** о вершинах входного файла.
*/

int		get_color(char *value)
{
	int		color;
	int		k;
	char	*hex;

	hex = "0123456789abcdef";
	color = 0;
	ft_stolower(value);
	while (*value)
		if (*(value++) == 'x')
			while (*value)
			{
				k = -1;
				if (*value < '0' || (*value > '9' && *value < 'a') ||
						*value > 'f')
					return (0xFFFFFF);
				while (hex[++k])
					if (hex[k] == *value)
					{
						color = color * 16 + k;
						break ;
					}
				value++;
			}
	return (color == 0 ? 0xFFFFFF : color);
}

/*
** В fill_list() приходит ссылка на next листа (который всегда NULL) или
** на самый первый *peaks (который тоже в начале NULL).
** К ним добавляются новые элементы
*/

int		fill_list(t_peak **next, char **xzcolor, int y)
{
	t_peak	*tmp;
	int		i;

	if ((*next = (t_peak*)malloc(sizeof(t_peak))) == 0)
		return (0);
	tmp = *next;
	i = -1;
	while (xzcolor[++i])
	{
		tmp->x = i;
		tmp->y = y;
		tmp->z = ft_atoi(xzcolor[i]);
		tmp->color = get_color(xzcolor[i]);
		if (xzcolor[i + 1])
		{
			if ((tmp->next = (t_peak*)malloc(sizeof(t_peak))) == 0)
				return (0);
			tmp = tmp->next;
		}
		else
			tmp->next = NULL;
	}
	return (1);
}

int		get_data(int fd, t_peak **peaks)
{
	char	**xzcolor;
	char	*buf;
	t_peak	*tmp;
	int		y;

	y = 0;
	(*peaks) = NULL;
	while (get_next_line(fd, &buf) > 0)
		if (buf[0])
		{
			xzcolor = ft_strsplit(buf, ' ');
			if (*peaks)
			{
				tmp = *peaks;
				while (tmp->next)
					tmp = tmp->next;
				if (!fill_list(&(tmp->next), xzcolor, y))
					return (0);
			}
			else if (!fill_list(peaks, xzcolor, y))
				return (0);
			y++;
		}
	return (1);
}
