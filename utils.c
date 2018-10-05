/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:20:46 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:25:03 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collector.h>

/*
** Responsible for printing all erros associated with the garbage collector
** uses a fixed buffer[1024] to avoid calling the kernel multiple times.
*/

void		panic(const char *ptr)
{
	unsigned char	*s;
	size_t			ret;
	size_t			len;

	len = g_strlen((char *)ptr);
	s = (unsigned char *)ptr;

	ret = 0;
	while (ret < len)
		ret += write(2, s + ret, ((ret + 1024) > len) ? len - ret : 1024);
}
