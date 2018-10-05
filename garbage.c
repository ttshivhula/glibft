/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:27:20 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:31:09 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collector.h>

/*
** Returns a free block that is enough for the user.
*/

void		*get_free(t_garbage **gb, size_t size)
{
	t_garbage *tmp;

	tmp = *gb;
	while (tmp)
	{
		if ((tmp->size >= size) && (tmp->free > 0))
		{
			tmp->free = 0;
			return (tmp->ptr);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

/*
** Allocates the user requested blocks and then returns a pointer to the
** memory available to the user.
*/

void		*alloc_mem(t_garbage **gb, size_t size)
{
	t_garbage	*tmp;
	void		*ptr;

	ptr = (*gb) ?  get_free(gb, size) : NULL;
	if ((size > 0) && (ptr == NULL))
	{
		if (*gb == NULL)
		{
			*gb = (t_garbage *)malloc(sizeof(t_garbage) + size);
			(*gb)->magic = GMAGIC;
			(*gb)->size = size;
			(*gb)->free = 0;
			(*gb)->next = NULL;
			return ((*gb)->ptr);
		}
		tmp = (t_garbage *)malloc(sizeof(t_garbage) + size);
		tmp->next = *gb;
		tmp->magic = GMAGIC;
		tmp->size = size;
		tmp->free = 0;
		*gb = tmp;
		return ((*gb)->ptr);
	}
	return (ptr);
}

/*
** Set a block as free but doesn't actually free the block to reduce the
** number of calls to malloc.
*/

void		garbage_free(void *ptr)
{
	t_garbage		*tmp;
	unsigned char	*s;

	s = (unsigned char *)ptr;
	tmp = (t_garbage *)(s - (sizeof(t_garbage) - sizeof(size_t)));
	if (tmp->magic == GMAGIC)
		tmp->free = 1;
	else
		panic("pointer can not be collected.\n");
}

/*
** Destorys a specific block and then frees the block, should only 
** be called only when user is sure that the block has to be deleted.
*/

void		garbage_kill(t_garbage **head_ref, void *ptr)
{
	t_garbage	*temp;
	t_garbage	*prev;

	temp = *head_ref;
	if (temp != NULL && temp->ptr == ptr)
	{
		*head_ref = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && temp->ptr != ptr)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}

/*
** Frees all blocks allocated using the GMALLOC this should only be called
** at the end of the program since it frees everythinh.
*/

void		garbage_collect(t_garbage *head)
{
   t_garbage	*tmp;
   
   while (head != NULL)
   {
	   tmp = head;
	   head = head->next;
	   free(tmp);
   }
}
