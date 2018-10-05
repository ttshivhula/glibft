/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:13:54 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:19:23 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glibft.h>
#include <stdio.h>

char	*cpy(t_garbage **gb, char *s)
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

void	check_mem_alloc(t_garbage *g)
{
	while (g)
	{
		printf("size: %zu free: %d ptr: %p\n", g->size, g->free, g->ptr);
		g = g->next;
	}
}

int		main(void)
{
	char		*str;
	t_garbage	*mem = NULL;
	char		*test;

	test = GMALLOC(&mem, 10000);
	//GFREE(test);
	GKILL(&mem, test);
	str = g_strdup(&mem, "fuck");
	printf("%s\n", str);
	GKILL(&mem, str);
	str = cpy(&mem, "test");
	GKILL(&mem, str);
	printf("%s\n", str);
	check_mem_alloc(mem);
	//GCOLLECT(mem);
	return (0);
}
