/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:25:14 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:31:22 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COLLECTOR_H
# define COLLECTOR_H

# include <stdlib.h>
# include <unistd.h>
# define GMAGIC 0x19960214
# define GMALLOC(ptr, size) alloc_mem(ptr, size)
# define GCOLLECT(ptr) garbage_collect(ptr)
# define GFREE(ptr) garbage_free(ptr)
# define GKILL(gb, ptr) garbage_kill(gb, ptr)

typedef	struct			s_garbage
{
	int					magic;
	int					free;
	size_t				size;
	struct s_garbage	*next;
	char				ptr[1];
}						t_garbage;

void					*alloc_mem(t_garbage **gb, size_t size);
void					garbage_collect(t_garbage *head);
void					garbage_free(void *ptr);
void					garbage_kill(t_garbage **head_ref, void *ptr);
void					panic(const char *ptr);
size_t					g_strlen(char *s);

#endif
