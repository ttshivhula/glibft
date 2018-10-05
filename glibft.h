/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glibft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:31 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/04 08:39:52 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GLIBFT
# define GLIBFT

# include <unistd.h>
# include <string.h>
# include <collector.h>

size_t		g_strlen(char *s);
char		*g_strdup(t_garbage **g, char *str);
char		*g_strcpy(char *dst, const char *src);

#endif
