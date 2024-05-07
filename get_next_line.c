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
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1 
#endif

size_t	ft_strlen_buffer(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	int	status;
	char	buffer[BUFFER_SIZE];
	static char	static_buffer;
	char	*str;
	
	status = read(fd, buffer, sizeof(buffer));
	str = ft_substr(buffer ,ft_strchr(buffer, '\n', ft_strlen_buffer(buffer)); 
	str = malloc(sizeof(char) * (sizeof(buffer) + 1));
	if (str == NULL)
		return (NULL);	
	return (str);	
}

int	main(void)
{
	char	*str;
	int	fd;
	int	i;
	
	i = 0;
	fd = open("get_next_line.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error1\n", 7);
		return (1);
	}
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	return (0);
}
