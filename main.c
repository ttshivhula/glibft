/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:13:54 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/03 14:50:54 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glibft.h>
#include <stdio.h>

char	*cpy(t_garbege **gb, char *s)
{
	char	*ret;
	int		i;

	ret = GMALLOC(gb, g_strlen(s) * sizeof(char) + 1);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

int		main(void)
{
	char		*str;
	t_garbege	*mem = NULL;

	str = g_strdup(&mem, "fuck");
	printf("%s\n", str);
	str = cpy(&mem, "test");
	printf("%s\n", str);
	GCOLLECT(mem);
	return (0);
}
