/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:25:14 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/03 14:35:39 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COLLECTOR_H
# define COLLECTOR_H

# include <stdlib.h>
# define GMALLOC(ptr, size) alloc_mem(ptr, size)
# define GCOLLECT(ptr) garbage_collect(ptr)

typedef	struct			s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbege;

void					*alloc_mem(t_garbege **gb, size_t size);
void					garbage_collect(t_garbege *head);

#endif
