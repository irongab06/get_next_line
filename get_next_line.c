/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:30:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/08 16:42:07 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1 
#endif

//get_line

//get_left_over

char	*get_entire_line(char *buffer, char *line, int len, int	fd)
{
	int	count;
	
	count = 0;
	while (count != 1)
	{	
		len = read(fd, buffer, BUFFER_SIZE);
		count = ft_strchr(buffer, '\n');
		if (count == 0)

		{
			line = ft_strjoin(line, buffer);
		}
	}
	line = ft_strjoin(line, buffer);
	return (line);
	
}
/*
	boucle tant que != '\n'
	return toute la line avec \n et le reste
*/


char	*get_next_line(int fd)
{
	int		len;
	//static char	*left_over;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	line = NULL;
	len = 0;
	line = get_entire_line(buffer, line, len, fd);
	//line = get_line();
	//left_over = get_left_over();

	return (line);
}


int	main(int argc, char **argv)
{
	int	fd;
	int	nbr_of_lines = 1;

	if (argc > 1)
		nbr_of_lines = atoi(argv[1]);
	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < nbr_of_lines; ++i)
		printf("%d. \"%s\"\n", i, get_next_line(fd));
	return (0);
}
/*
	//len = read(fd, buffer, BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == 0)
	{
		free();	
		return (NULL);
	}
*/
