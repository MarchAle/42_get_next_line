/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:51 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/30 10:53:45 by amarchal         ###   ########.fr       */
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

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
			dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
}

char	*ft_fill_str(char *str, char *s1, char*s2)
{
	int		i;

	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
	{
		if (*s2 == '\n')
		{
			str[i++] = *s2++;
			break ;
		}
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	str = ft_fill_str(str, s1, s2);
	free(s1);
	return (str);
}

int	ft_end_of_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
