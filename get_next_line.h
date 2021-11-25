/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:16 by amarchal          #+#    #+#             */
/*   Updated: 2021/11/25 17:00:27 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
int	ft_end_of_line(char *buff);
char	*ft_strjoin(char *s1, char *s2);
void    ft_strcpy(char *dest, char *src);