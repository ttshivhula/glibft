/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:13:54 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/03 14:35:38 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collector.h>
#include <stdio.h>
#include <string.h>

char	*cpy(t_garbege **gb, char *s)
{
	char	*ret;
	int		i;

	ret = GMALLOC(gb, strlen(s) * sizeof(char) + 1);
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

	str = cpy(&mem, "test");
	printf("%s\n", str);
	GCOLLECT(mem);
	return (0);
}
