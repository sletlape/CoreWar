/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:23:37 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:23:38 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list*)malloc(sizeof(t_list))))
	{
		node->content = 0;
		node->content_size = 0;
		node->next = 0;
		if (content && (node->content = malloc(content_size)))
		{
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			free(node);
			return (0);
		}
	}
	return (node);
}
