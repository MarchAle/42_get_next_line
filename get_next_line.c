/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:36 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/24 17:59:30 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
	{
		if (*s2 == 10)
		{
			str[i++] = *s2++;
			break ;
		}
		str[i++] = *s2++;
	}
	str[i] = '\0';
	// if (s1)
	// 	free(s1);
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

char	*get_next_line(int fd)
{
	char 			*next_line;
	int				ret;
	static char		*fd_buff[FOPEN_MAX];

	printf("\n\nBUFFER EN ENTREE : || %s ||\n", fd_buff[fd]);

	next_line = "";
	ret = 0;
	if (fd == -1)
		return (NULL);
	if (fd_buff[fd] && ft_end_of_line(fd_buff[fd]) != ft_strlen(fd_buff[fd]) && ft_end_of_line(fd_buff[fd]) != -1)
	{
		next_line = ft_strjoin(next_line, fd_buff[fd]);
		fd_buff[fd] = fd_buff[fd] + ft_end_of_line(fd_buff[fd]) + 1;
		return (next_line);	
	}
	else if (fd_buff[fd])
	{
		next_line = ft_strjoin(next_line, fd_buff[fd]);
	}
	fd_buff[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd_buff[fd][BUFFER_SIZE] = '\0';
	while (1)
	{
		ret = read(fd, fd_buff[fd], BUFFER_SIZE);
		if (ret == 0 && ft_strlen(next_line) == 0)
			return (NULL);
		if (ft_end_of_line(fd_buff[fd]) != -1 || ret == 0)
		{
			next_line = ft_strjoin(next_line, fd_buff[fd]);
			fd_buff[fd] = fd_buff[fd] + ft_end_of_line(fd_buff[fd]) + 1;
			return (next_line);	
		}
		next_line = ft_strjoin(next_line, fd_buff[fd]);
	}
}

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*str;
	
	str = "";
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	// printf("\n GO \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n - \n\n");
	// printf("//// 		Ligne retournée : %s		\\\\\\\\\\\n", get_next_line(fd));
	// printf("\n END \n\n");

	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	
	return (0);
}