/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:05:17 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/17 00:25:04 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int			start;
	int			end;
	char		*newstr;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (iswhitespace(s[start]))
		start++;
	while (iswhitespace(s[end - 1]))
		end--;
	end = (start > end) ? 0 : end - start;
	if (!(newstr = ft_strnew(end)))
		return (NULL);
	ft_strncpy(newstr, &s[start], end);
	return (newstr);
}
