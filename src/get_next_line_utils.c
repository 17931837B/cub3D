/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:01:45 by tashiget          #+#    #+#             */
/*   Updated: 2024/03/21 22:01:45 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	k;

	k = 0;
	while (*(str + k))
		k++;
	return (k);
}

void	catstrlen2(char *dest, char *dup, ssize_t len, char *src)
{
	ssize_t	l_d;
	ssize_t	n;
	ssize_t	m;

	l_d = ft_strlen(dest);
	n = 0;
	while (n < l_d)
	{
		*(dup + n) = *(dest + n);
		n++;
	}
	m = 0;
	while (m < len)
	{
		*(dup + n + m) = *(src + m);
		m++;
	}
	*(dup + n + m) = '\0';
}

char	*catstrlen(char *dest, char *src, ssize_t len)
{
	ssize_t	l_d;
	char	*dup;

	l_d = ft_strlen(dest);
	dup = (char *)malloc(sizeof(char) * (l_d + len + 1));
	if (!dup)
	{
		free(dest);
		return (0);
	}
	catstrlen2(dest, dup, len, src);
	free(dest);
	return (dup);
}
