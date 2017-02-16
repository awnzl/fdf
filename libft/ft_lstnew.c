/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:37:09 by avenzel           #+#    #+#             */
/*   Updated: 2016/12/12 15:12:56 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t size)
{
	t_list	*fresh;

	if ((fresh = (t_list*)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if (data)
	{
		if ((fresh->data = (void*)malloc(size)) == 0)
			return (NULL);
		ft_memcpy(fresh->data, (void*)data, size);
		fresh->size = size;
		fresh->next = NULL;
	}
	else
	{
		fresh->data = NULL;
		fresh->size = 0;
		fresh->next = NULL;
	}
	return (fresh);
}
