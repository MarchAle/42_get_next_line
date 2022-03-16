/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:36 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/30 11:02:41 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line(char *line, char *buff, int fd)
{
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		line = ft_strjoin(line, buff);
		if (line == NULL)
			return (NULL);
		if (ft_end_of_line(buff) != -1)
		{
			ft_strcpy(buff, buff + ft_end_of_line(buff) + 1);
			return (line);
		}
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
		buff[ret] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1] = {{'\0'}};
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_fill_line(line, buff[fd], fd);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

int	main(void)
{
	printf("%s\n", get_next_line(3));
	printf("%s\n", get_next_line(3));
}
