/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:14:57 by avenzel           #+#    #+#             */
/*   Updated: 2017/01/31 16:07:49 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fds	*checkfd(int fd, t_fds **fds)
{
	t_fds *el;
	t_fds *tmp;

	el = *fds;
	while (el)
	{
		if (el->fd == fd)
			return (el);
		el = el->next;
	}
	if ((el = (t_fds*)malloc(sizeof(t_fds))) == 0)
		return (NULL);
	el->fd = fd;
	el->bf = ft_strnew(0);
	el->next = NULL;
	tmp = *fds;
	if (!(*fds))
		return (*fds = el);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = el;
	return (el);
}

int		isnl(char *bf, int i)
{
	int k;

	k = -1;
	while (bf[++k] && i--)
		if (bf[k] == '\n')
			return (k);
	return (-1);
}

int		fills(char *buff, char **s)
{
	int i;

	i = -1;
	while (buff[++i])
		if (buff[i] == 10)
			break ;
	if (((*s) = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (0);
	(*s)[i] = 0;
	while (i--)
		(*s)[i] = buff[i];
	return (1);
}

int		to_buff(t_fds *rest, char *arr, int bts, char **s)
{
	char	*buf;
	char	*tmp;

	buf = ft_strnew(bts + 1);
	ft_strncpy(buf, arr, bts);
	tmp = rest->bf;
	rest->bf = ft_strjoin(tmp, buf);
	free(buf);
	free(tmp);
	if (isnl(rest->bf, ft_strlen(rest->bf)) >= 0)
	{
		fills(rest->bf, s);
		tmp = rest->bf;
		rest->bf = ft_strdup(tmp + isnl(tmp, ft_strlen(tmp)) + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **s)
{
	static t_fds	*fds;
	t_fds			*tmpfd;
	int				bts;
	char			arr[BUFF_SIZE];

	if (!(tmpfd = checkfd(fd, &fds)) && (fd < 0 || s == NULL))
		return (-1);
	if (tmpfd->bf[0])
		if ((bts = isnl(tmpfd->bf, ft_strlen(tmpfd->bf))) >= 0)
		{
			fills(tmpfd->bf, s);
			tmpfd->bf = ft_strdup(tmpfd->bf + bts + 1);
			return (1);
		}
	while ((bts = read(fd, arr, BUFF_SIZE)) >= 0)
		if (to_buff(tmpfd, arr, bts, s) && bts > 0)
			return (1);
		else if (bts == 0 && tmpfd->bf[0])
			return (to_buff(tmpfd, "\n", 1, s));
		else if (bts == 0 && !tmpfd->bf[0])
			break ;
	if (bts < 0)
		return (-1);
	fills("", s);
	return (0);
}
