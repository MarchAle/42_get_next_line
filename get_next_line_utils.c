/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:51 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/25 17:00:32 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void    ft_strcpy(char *dest, char *src)
{
        int     i;

        i = 0;
        while (src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
}