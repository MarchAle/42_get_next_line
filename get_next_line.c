/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:36 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/25 18:18:33 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s1);
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
	printf("s1 : %s\n", s1 - s_len);
	free(s1 - s_len);
	str[i] = '\0';
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
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1] = {{'\0'}};
	char		*line;
	int			ret;
	
	ret = -1;
	line = malloc(1);
	while (ret != 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (ft_end_of_line(buff[fd]) != -1 && ret != 0)
		{
			ft_strcpy(buff[fd], buff[fd] + ft_end_of_line(buff[fd]) + 1);
			return (line);
		}
		ret = read(fd, buff[fd], BUFFER_SIZE);
		buff[fd][ret] = '\0';
	}
	if (ft_strlen(line))
		return (line);
	return (NULL);
}

// char	*get_next_line(int fd)
// {
// 	char 			*next_line;
// 	char 			*temp;
// 	int				ret;
// 	static char		fd_buff[FOPEN_MAX][BUFFER_SIZE + 1] = {{0}};

// 	// free(fd_buff);
// 	next_line = malloc(sizeof(char) * 1);
// 	ret = 0;
// 	if (fd == -1)
// 		return (NULL);
// 	if (fd_buff[fd] && ft_end_of_line(fd_buff[fd]) != ft_strlen(fd_buff[fd]) && ft_end_of_line(fd_buff[fd]) != -1)
// 	{
// 		temp = next_line;
// 		free(next_line);
// 		next_line = ft_strjoin(temp, fd_buff[fd]);
// 		fd_buff[fd] = fd_buff[fd] + ft_end_of_line(fd_buff[fd]) + 1;
// 		return (next_line);	
// 	}
// 	else if (fd_buff[fd])
// 	{
// 		temp = next_line;
// 		free(next_line);
// 		next_line = ft_strjoin(temp, fd_buff[fd]);
// 	}
// 	while (1)
// 	{
// 		// if (fd_buff[fd] == 0)
// 		// 	free(fd_buff[fd]);
// 		// fd_buff[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		ret = read(fd, fd_buff[fd], BUFFER_SIZE);
// 		// printf("ICI ret = %d\n", ret);
// 		// fd_buff[fd][ret] = '\0';
// 		if (ret == 0 && ft_strlen(next_line) == 0)
// 		{
// 			return (NULL);
// 		}
// 		if (ft_end_of_line(fd_buff[fd]) != -1)
// 		{
// 			temp = next_line;
// 			free(next_line);
// 			next_line = ft_strjoin(temp, fd_buff[fd]);
// 			fd_buff[fd] = fd_buff[fd] + ft_end_of_line(fd_buff[fd]) + 1;
// 			return (next_line);	
// 		}
// 		if (ret != BUFFER_SIZE)
// 		{
// 			temp = next_line;
// 			free(next_line);
// 			next_line = ft_strjoin(temp, fd_buff[fd]);
// 			fd_buff[fd] = fd_buff[fd] + ft_strlen(fd_buff[fd]);
// 			return (next_line);	
// 		}
// 		temp = next_line;
// 		free(next_line);
// 		next_line = ft_strjoin(temp, fd_buff[fd]);
// 	}
// }

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
	// printf("-line %d : %s", fd, get_next_line(fd));
	// printf("\n");
	// printf("-line %d : %s", fd2, get_next_line(fd2));
	// printf("\n");
	// printf("-line %d : %s", fd2, get_next_line(fd2));
	// printf("\n");
	// printf("-line %d : %s", fd, get_next_line(fd));
	// printf("\n");
	// printf("-line %d : %s", fd3, get_next_line(fd3));
	// printf("\n");
	// printf("-line %d : %s", fd, get_next_line(fd));
	// printf("\n");
	// printf("-line %d : %s", fd, get_next_line(fd));
	// printf("\n");
	// printf("-line %d : %s", fd2, get_next_line(fd2));
	// printf("\n");
	// printf("-line %d : %s", fd3, get_next_line(fd3));
	// printf("\n END \n\n");

	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("-line- : %s", str);
	}
	
	// int	i = 0;
	// while (i < 15)
	// {
	// 	str = get_next_line(fd);
	// 	printf("-line %d - : %s", fd, str);
	// 	i++;
	// }
	
	return (0);
}