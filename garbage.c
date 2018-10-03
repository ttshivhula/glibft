/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:27:20 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/03 14:28:48 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collector.h>

void		*alloc_mem(t_garbege **gb, size_t size)
{
	t_garbege	*tmp;
	void		*ptr;

	if (size > 0)
	{
		if (!*gb)
		{
			*gb = (t_garbege *)malloc(sizeof(t_garbege));
			(*gb)->ptr = malloc(size);
			(*gb)->next = NULL;
			return ((*gb)->ptr);
		}
		tmp = (t_garbege *)malloc(sizeof(t_garbege));
		tmp->ptr = malloc(size);
		tmp->next = *gb;
		*gb = tmp;
		return ((*gb)->ptr);
	}
	return (ptr);
}

void		garbage_collect(t_garbege *head)
{
   t_garbege	*tmp;
   
   while (head != NULL)
   {
	   tmp = head;
	   head = head->next;
	   free(tmp->ptr);
	   free(tmp);
   }
}
