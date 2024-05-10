/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:35:03 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/09 15:44:21 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst && src && size)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (src_len);
}


char	*get_line(char **leftover)
{
	char	*new_line;
	char	*temp;
	size_t	len;
	
	len = ft_strchr(*leftover, '\n') - *leftover + 1;
	//--------------------------------
	//printf("ft_strchr: %s\n", ft_strchr(*leftover, '\n'));
	//printf("Leftover4 %s\n", *leftover);
	//printf("Len: %zu\n", len);
	//------------------------------------
	new_line = ft_substr(*leftover, 0, len);
	//-------------------------------------
	//printf("new_line: %s\n", new_line);
	//---------------------------------------
	temp = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
	free(*leftover);
	*leftover = NULL;
	if (temp != NULL)
		*leftover = ft_strjoin(NULL, temp);	
	free(temp);
	return (new_line);
}

char	*get_entire_line(char *buffer, char *leftover, int fd)
{
	char	*temp;
	int	len;

	len = 0;	
	temp = NULL;
	while (!ft_strchr(leftover, '\n') && (len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (len <= 0)
			return (NULL);
		buffer[len] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (leftover)
			free(leftover);
		leftover = ft_strjoin(NULL, temp);
		free(temp);
	}
	return (leftover);
	// je recupere avant le \n je le renvoi et je stock ce qu'il uy a apres .

}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	static char	*leftover;
	
	if (fd < 0)
		return (NULL);
	leftover = get_entire_line(buffer, leftover, fd);
	//printf("Leftover3 %s\n", leftover);

	// verrifier si leftover est nul ne pas oublier.
	
	line = get_line(&leftover);
	if (!ft_strlen(leftover))
	{
		free(leftover);
		leftover = NULL;
	}
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	int	nbr_of_lines = 1;
	char	*str;

	if (argc > 1)
		nbr_of_lines = atoi(argv[1]);
	fd = open("testn.txt", O_RDONLY);
	for (int i = 0; i < nbr_of_lines; ++i)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);		
	}
	return (0);
}
*/
