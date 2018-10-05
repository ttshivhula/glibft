/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:40:50 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/04 08:36:00 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glibft.h>

size_t	g_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*g_strdup(t_garbage **g, char *str)
{
	unsigned int	i;
	char			*ret;

	i = -1;
	ret = GMALLOC(g, g_strlen(str) * sizeof(char) + 1);
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

char	*g_strcpy(char *dst, const char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
