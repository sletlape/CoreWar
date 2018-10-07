/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:51:44 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 00:24:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		spaceless_len(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	i -= j;
	return (i);
}

char	*ft_strdefix(char *str, int c)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = -1;
	j = -1;
	while (str[++i] && str[i] != c)
		;
	len = spaceless_len(str);
	newstr = ft_strnew((unsigned int)len - i);
	while (str[++i] != '\0')
	{
		if (str[i] == 32)
		{
			while (str[i] == 32)
				i++;
		}
		newstr[++j] = str[i];
	}
	return (newstr);
}
