/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:30:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/07 15:13:38 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1 
#endif

size_t	ft_strlen_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' || buffer[i] != '\0')
	{
		i++;
	}
	i++;
	return (i);
}

void	get_line(char *buffer, char *str)
{
	size_t	i;
	static char	str_static;
	
	i = ft_strlen_buffer(buffer);
	str = malloc(sizeof(char) * (i + 1));
	str = ft_substr(buffer, ft_strchr(buffer, '\n'), i);
}

int	ft_read(int fd, char *buffer)
{
	int	inter;

	inter = read(fd, buffer, sizeof(buffer));
	if 
	return (inter);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	static char	static_buffer;
	char	*str;
	
	while ((ft_read(fd, buffer) > 0)
	}
		get_line(buffer, str);	
	{
	return (str);	
}

int	main(void)
{
	char	str[20];
	int	fd;
	int	i;
	
	i = 0;
	fd = open("get_next_line.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error1\n", 7);
		return (1);
	}
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
